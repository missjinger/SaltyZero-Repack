/*
 * Copyright (C) 2016+     AzerothCore <www.azerothcore.org>
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 */

#ifndef AZEROTHCORE_FIELD_H
#define AZEROTHCORE_FIELD_H

#include "Common.h"
#include "Log.h"

#include <mysql.h>

class Field
{
    friend class ResultSet;
    friend class PreparedResultSet;

    public:

        template<class T> T GetValue() const
        {
            if (!data.value)
                return 0;

            #ifdef TRINITY_DEBUG
            // TODO: check types by binary bit
            #endif

            if (data.raw)
                return *reinterpret_cast<T*>(data.value);
            return static_cast<T>(atol((char*)data.value));
        }

        template<> bool GetValue<bool>() const
        {
            return GetValue<uint8>() == 1 ? true : false;
        }

        template<> int64 GetValue<int64>() const
        {
            if (!data.value)
                return 0;

            #ifdef TRINITY_DEBUG
            if (!IsType(MYSQL_TYPE_LONGLONG) && !IsType(MYSQL_TYPE_BIT))
            {
                sLog->outSQLDriver("Warning: GetInt64() on non-bigint field. Using type: %s.", FieldTypeToString(data.type));
                return 0;
            }
            #endif

            if (data.raw)
                return *reinterpret_cast<int64*>(data.value);
            return static_cast<int64>(strtol((char*)data.value, NULL, 10));
        }

#ifdef ELUNA
        enum_field_types GetType() const
        {
            return data.type;
        }
#endif

        template<> float GetValue<float>() const
        {
            if (!data.value)
                return 0.0f;

            #ifdef TRINITY_DEBUG
            if (!IsType(MYSQL_TYPE_FLOAT))
            {
                sLog->outSQLDriver("Warning: GetFloat() on non-float field. Using type: %s.", FieldTypeToString(data.type));
                return 0.0f;
            }
            #endif

            if (data.raw)
                return *reinterpret_cast<float*>(data.value);
            return static_cast<float>(atof((char*)data.value));
        }

        template<> double GetValue<double>() const
        {
            if (!data.value)
                return 0.0f;

            #ifdef TRINITY_DEBUG
            if (!IsType(MYSQL_TYPE_DOUBLE))
            {
                sLog->outSQLDriver("Warning: GetDouble() on non-double field. Using type: %s.", FieldTypeToString(data.type));
                return 0.0f;
            }
            #endif

            if (data.raw)
                return *reinterpret_cast<double*>(data.value);
            return static_cast<double>(atof((char*)data.value));
        }

        template<> CString GetValue<CString>() const
        {
            if (!data.value)
                return NULL;

            #ifdef TRINITY_DEBUG
            if (IsNumeric())
            {
                sLog->outSQLDriver("Error: GetCString() on numeric field. Using type: %s.", FieldTypeToString(data.type));
                return NULL;
            }
            #endif
            return static_cast<char const*>(data.value);
        }

        template<> std::string GetValue<std::string>() const
        {
            if (!data.value)
                return "";

            if (data.raw)
            {
                char const* string = GetValue<CString>();
                if (!string)
                    string = "";
                return std::string(string, data.length);
            }
            return std::string((char*)data.value);
        }

        bool IsNull() const
        {
            return data.value == NULL;
        }

    protected:
        Field();
        ~Field();

        #if defined(__GNUC__)
        #pragma pack(1)
        #else
        #pragma pack(push, 1)
        #endif
        struct
        {
            uint32 length;          // Length (prepared strings only)
            void* value;            // Actual data in memory
            enum_field_types type;  // Field type
            bool raw;               // Raw bytes? (Prepared statement or ad hoc)
         } data;
        #if defined(__GNUC__)
        #pragma pack()
        #else
        #pragma pack(pop)
        #endif

        void SetByteValue(void const* newValue, size_t const newSize, enum_field_types newType, uint32 length);
        void SetStructuredValue(char* newValue, enum_field_types newType);

        void CleanUp()
        {
            delete[] ((char*)data.value);
            data.value = NULL;
        }

        static size_t SizeForType(MYSQL_FIELD* field)
        {
            switch (field->type)
            {
                case MYSQL_TYPE_NULL:
                    return 0;
                case MYSQL_TYPE_TINY:
                    return 1;
                case MYSQL_TYPE_YEAR:
                case MYSQL_TYPE_SHORT:
                    return 2;
                case MYSQL_TYPE_INT24:
                case MYSQL_TYPE_LONG:
                case MYSQL_TYPE_FLOAT:
                    return 4;
                case MYSQL_TYPE_DOUBLE:
                case MYSQL_TYPE_LONGLONG:
                case MYSQL_TYPE_BIT:
                    return 8;

                case MYSQL_TYPE_TIMESTAMP:
                case MYSQL_TYPE_DATE:
                case MYSQL_TYPE_TIME:
                case MYSQL_TYPE_DATETIME:
                    return sizeof(MYSQL_TIME);

                case MYSQL_TYPE_TINY_BLOB:
                case MYSQL_TYPE_MEDIUM_BLOB:
                case MYSQL_TYPE_LONG_BLOB:
                case MYSQL_TYPE_BLOB:
                case MYSQL_TYPE_STRING:
                case MYSQL_TYPE_VAR_STRING:
                    return field->max_length + 1;

                case MYSQL_TYPE_DECIMAL:
                case MYSQL_TYPE_NEWDECIMAL:
                    return 64;

                case MYSQL_TYPE_GEOMETRY:
                /*
                Following types are not sent over the wire:
                MYSQL_TYPE_ENUM:
                MYSQL_TYPE_SET:
                */
                default:
                    sLog->outSQLDriver("SQL::SizeForType(): invalid field type %u", uint32(field->type));
                    return 0;
            }
        }

        bool IsType(enum_field_types type) const
        {
            return data.type == type;
        }

        bool IsNumeric() const
        {
            return (data.type == MYSQL_TYPE_TINY ||
                    data.type == MYSQL_TYPE_SHORT ||
                    data.type == MYSQL_TYPE_INT24 ||
                    data.type == MYSQL_TYPE_LONG ||
                    data.type == MYSQL_TYPE_FLOAT ||
                    data.type == MYSQL_TYPE_DOUBLE ||
                    data.type == MYSQL_TYPE_LONGLONG );
        }

    private:
        // TODO: sort types by binary bit
        #ifdef TRINITY_DEBUG
        static char const* FieldTypeToString(enum_field_types type)
        {
            switch (type)
            {
                case MYSQL_TYPE_BIT:         return "BIT";
                case MYSQL_TYPE_BLOB:        return "BLOB";
                case MYSQL_TYPE_DATE:        return "DATE";
                case MYSQL_TYPE_DATETIME:    return "DATETIME";
                case MYSQL_TYPE_NEWDECIMAL:  return "NEWDECIMAL";
                case MYSQL_TYPE_DECIMAL:     return "DECIMAL";
                case MYSQL_TYPE_DOUBLE:      return "DOUBLE";
                case MYSQL_TYPE_ENUM:        return "ENUM";
                case MYSQL_TYPE_FLOAT:       return "FLOAT";
                case MYSQL_TYPE_GEOMETRY:    return "GEOMETRY";
                case MYSQL_TYPE_INT24:       return "INT24";
                case MYSQL_TYPE_LONG:        return "LONG";
                case MYSQL_TYPE_LONGLONG:    return "LONGLONG";
                case MYSQL_TYPE_LONG_BLOB:   return "LONG_BLOB";
                case MYSQL_TYPE_MEDIUM_BLOB: return "MEDIUM_BLOB";
                case MYSQL_TYPE_NEWDATE:     return "NEWDATE";
                case MYSQL_TYPE_NULL:        return "NULL";
                case MYSQL_TYPE_SET:         return "SET";
                case MYSQL_TYPE_SHORT:       return "SHORT";
                case MYSQL_TYPE_STRING:      return "STRING";
                case MYSQL_TYPE_TIME:        return "TIME";
                case MYSQL_TYPE_TIMESTAMP:   return "TIMESTAMP";
                case MYSQL_TYPE_TINY:        return "TINY";
                case MYSQL_TYPE_TINY_BLOB:   return "TINY_BLOB";
                case MYSQL_TYPE_VAR_STRING:  return "VAR_STRING";
                case MYSQL_TYPE_YEAR:        return "YEAR";
                default:                     return "-Unknown-";
            }
        }
        #endif
};

#endif


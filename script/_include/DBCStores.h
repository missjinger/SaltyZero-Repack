/*
 * Copyright (C) 2016+     AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-GPL2
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 */

#ifndef TRINITY_DBCSTORES_H
#define TRINITY_DBCSTORES_H

#include "Common.h"
#include "DBCStore.h"
#include "DBCStructure.h"

#include <list>

typedef std::list<uint32> SimpleFactionsList;
SimpleFactionsList const* GetFactionTeamList(uint32 faction);

char* GetPetName(uint32 petfamily, uint32 dbclang);
uint32 GetTalentSpellCost(uint32 spellId);
TalentSpellPos const* GetTalentSpellPos(uint32 spellId);

WMOAreaTableEntry const* GetWMOAreaTableEntryByTripple(int32 rootid, int32 adtid, int32 groupid);

uint32 GetVirtualMapForMapAndZone(uint32 mapid, uint32 zoneId);

enum ContentLevels
{
    CONTENT_1_60 = 0,
    CONTENT_61_70,
    CONTENT_71_80
};
ContentLevels GetContentLevelsForMapAndZone(uint32 mapid, uint32 zoneId);

void Zone2MapCoordinates(float &x, float &y, uint32 zone);
void Map2ZoneCoordinates(float &x, float &y, uint32 zone);

typedef std::map<uint32/*pair32(map, diff)*/, MapDifficulty> MapDifficultyMap;
MapDifficulty const* GetMapDifficultyData(uint32 mapId, Difficulty difficulty);
MapDifficulty const* GetDownscaledMapDifficultyData(uint32 mapId, Difficulty &difficulty);

bool IsSharedDifficultyMap(uint32 mapid);

uint32 GetLiquidFlags(uint32 liquidType);

PvPDifficultyEntry const* GetBattlegroundBracketByLevel(uint32 mapid, uint32 level);
PvPDifficultyEntry const* GetBattlegroundBracketById(uint32 mapid, BattlegroundBracketId id);

CharStartOutfitEntry const* GetCharStartOutfitEntry(uint8 race, uint8 class_, uint8 gender);

LFGDungeonEntry const* GetLFGDungeon(uint32 mapId, Difficulty difficulty);
uint32 GetDefaultMapLight(uint32 mapId);

_extern DBCStorage <AchievementEntry>             sAchievementStore;
_extern DBCStorage <AchievementCriteriaEntry>     sAchievementCriteriaStore;
_extern DBCStorage <AchievementCategoryEntry>     sAchievementCategoryStore;
_extern DBCStorage <AreaTableEntry>               sAreaTableStore;
_extern DBCStorage <AreaGroupEntry>               sAreaGroupStore;
_extern DBCStorage <AreaPOIEntry>                 sAreaPOIStore;
_extern DBCStorage <AuctionHouseEntry>            sAuctionHouseStore;
_extern DBCStorage <BankBagSlotPricesEntry>       sBankBagSlotPricesStore;
_extern DBCStorage <BarberShopStyleEntry>         sBarberShopStyleStore;
_extern DBCStorage <BattlemasterListEntry>        sBattlemasterListStore;
_extern DBCStorage <ChatChannelsEntry>            sChatChannelsStore;
_extern DBCStorage <CharStartOutfitEntry>         sCharStartOutfitStore;
_extern DBCStorage <CharTitlesEntry>              sCharTitlesStore;
_extern DBCStorage <ChrClassesEntry>              sChrClassesStore;
_extern DBCStorage <ChrRacesEntry>                sChrRacesStore;
_extern DBCStorage <CinematicSequencesEntry>      sCinematicSequencesStore;
_extern DBCStorage <CreatureDisplayInfoEntry>     sCreatureDisplayInfoStore;
_extern DBCStorage <CreatureFamilyEntry>          sCreatureFamilyStore;
_extern DBCStorage <CreatureModelDataEntry>       sCreatureModelDataStore;
_extern DBCStorage <CreatureSpellDataEntry>       sCreatureSpellDataStore;
_extern DBCStorage <CreatureTypeEntry>            sCreatureTypeStore;
_extern DBCStorage <CurrencyTypesEntry>           sCurrencyTypesStore;
_extern DBCStorage <DestructibleModelDataEntry>   sDestructibleModelDataStore;
_extern DBCStorage <DungeonEncounterEntry>        sDungeonEncounterStore;
_extern DBCStorage <DurabilityCostsEntry>         sDurabilityCostsStore;
_extern DBCStorage <DurabilityQualityEntry>       sDurabilityQualityStore;
_extern DBCStorage <EmotesEntry>                  sEmotesStore;
_extern DBCStorage <EmotesTextEntry>              sEmotesTextStore;
_extern DBCStorage <FactionEntry>                 sFactionStore;
_extern DBCStorage <FactionTemplateEntry>         sFactionTemplateStore;
_extern DBCStorage <GameObjectDisplayInfoEntry>   sGameObjectDisplayInfoStore;
_extern DBCStorage <GemPropertiesEntry>           sGemPropertiesStore;
_extern DBCStorage <GlyphPropertiesEntry>         sGlyphPropertiesStore;
_extern DBCStorage <GlyphSlotEntry>               sGlyphSlotStore;

_extern DBCStorage <GtBarberShopCostBaseEntry>    sGtBarberShopCostBaseStore;
_extern DBCStorage <GtCombatRatingsEntry>         sGtCombatRatingsStore;
_extern DBCStorage <GtChanceToMeleeCritBaseEntry> sGtChanceToMeleeCritBaseStore;
_extern DBCStorage <GtChanceToMeleeCritEntry>     sGtChanceToMeleeCritStore;
_extern DBCStorage <GtChanceToSpellCritBaseEntry> sGtChanceToSpellCritBaseStore;
_extern DBCStorage <GtChanceToSpellCritEntry>     sGtChanceToSpellCritStore;
_extern DBCStorage <GtNPCManaCostScalerEntry>     sGtNPCManaCostScalerStore;
_extern DBCStorage <GtOCTClassCombatRatingScalarEntry> sGtOCTClassCombatRatingScalarStore;
_extern DBCStorage <GtOCTRegenHPEntry>            sGtOCTRegenHPStore;
//_extern DBCStorage <GtOCTRegenMPEntry>            sGtOCTRegenMPStore; -- not used currently
_extern DBCStorage <GtRegenHPPerSptEntry>         sGtRegenHPPerSptStore;
_extern DBCStorage <GtRegenMPPerSptEntry>         sGtRegenMPPerSptStore;
_extern DBCStorage <HolidaysEntry>                sHolidaysStore;
_extern DBCStorage <ItemBagFamilyEntry>           sItemBagFamilyStore;
_extern DBCStorage <ItemDisplayInfoEntry>         sItemDisplayInfoStore;
_extern DBCStorage <ItemExtendedCostEntry>        sItemExtendedCostStore;
_extern DBCStorage <ItemLimitCategoryEntry>       sItemLimitCategoryStore;
_extern DBCStorage <ItemRandomPropertiesEntry>    sItemRandomPropertiesStore;
_extern DBCStorage <ItemRandomSuffixEntry>        sItemRandomSuffixStore;
_extern DBCStorage <ItemSetEntry>                 sItemSetStore;
_extern DBCStorage <LFGDungeonEntry>           sLFGDungeonStore;
_extern DBCStorage <LiquidTypeEntry>              sLiquidTypeStore;
_extern DBCStorage <LockEntry>                    sLockStore;
_extern DBCStorage <MailTemplateEntry>            sMailTemplateStore;
_extern DBCStorage <MapEntry>                     sMapStore;
//_extern DBCStorage <MapDifficultyEntry>           sMapDifficultyStore; -- use GetMapDifficultyData insteed
_extern MapDifficultyMap                          sMapDifficultyMap;
_extern DBCStorage <MovieEntry>                   sMovieStore;
_extern DBCStorage <OverrideSpellDataEntry>       sOverrideSpellDataStore;
_extern DBCStorage <PowerDisplayEntry>            sPowerDisplayStore;
_extern DBCStorage <QuestSortEntry>               sQuestSortStore;
_extern DBCStorage <QuestXPEntry>                 sQuestXPStore;
_extern DBCStorage <QuestFactionRewEntry>         sQuestFactionRewardStore;
_extern DBCStorage <RandomPropertiesPointsEntry>  sRandomPropertiesPointsStore;
_extern DBCStorage <ScalingStatDistributionEntry> sScalingStatDistributionStore;
_extern DBCStorage <ScalingStatValuesEntry>       sScalingStatValuesStore;
_extern DBCStorage <SkillLineEntry>               sSkillLineStore;
_extern DBCStorage <SkillLineAbilityEntry>        sSkillLineAbilityStore;
_extern DBCStorage <SoundEntriesEntry>            sSoundEntriesStore;
_extern DBCStorage <SpellCastTimesEntry>          sSpellCastTimesStore;
_extern DBCStorage <SpellCategoryEntry>           sSpellCategoryStore;
_extern DBCStorage <SpellDifficultyEntry>         sSpellDifficultyStore;
_extern DBCStorage <SpellDurationEntry>           sSpellDurationStore;
_extern DBCStorage <SpellFocusObjectEntry>        sSpellFocusObjectStore;
_extern DBCStorage <SpellItemEnchantmentEntry>    sSpellItemEnchantmentStore;
_extern DBCStorage <SpellItemEnchantmentConditionEntry> sSpellItemEnchantmentConditionStore;
_extern SpellCategoryStore                        sSpellsByCategoryStore;
_extern PetFamilySpellsStore                      sPetFamilySpellsStore;
_extern DBCStorage <SpellRadiusEntry>             sSpellRadiusStore;
_extern DBCStorage <SpellRangeEntry>              sSpellRangeStore;
_extern DBCStorage <SpellRuneCostEntry>           sSpellRuneCostStore;
_extern DBCStorage <SpellShapeshiftEntry>         sSpellShapeshiftStore;
_extern DBCStorage <SpellEntry>                   sSpellStore;
_extern DBCStorage <StableSlotPricesEntry>        sStableSlotPricesStore;
_extern DBCStorage <SummonPropertiesEntry>        sSummonPropertiesStore;
_extern DBCStorage <TalentEntry>                  sTalentStore;
_extern DBCStorage <TalentTabEntry>               sTalentTabStore;
_extern DBCStorage <TaxiNodesEntry>               sTaxiNodesStore;
_extern DBCStorage <TaxiPathEntry>                sTaxiPathStore;
_extern TaxiMask                                  sTaxiNodesMask;
_extern TaxiMask                                  sOldContinentsNodesMask;
_extern TaxiMask                                  sHordeTaxiNodesMask;
_extern TaxiMask                                  sAllianceTaxiNodesMask;
_extern TaxiMask                                  sDeathKnightTaxiNodesMask;
_extern TaxiPathSetBySource                       sTaxiPathSetBySource;
_extern TaxiPathNodesByPath                       sTaxiPathNodesByPath;
_extern DBCStorage <TeamContributionPointsEntry>  sTeamContributionPointsStore;
_extern DBCStorage <TotemCategoryEntry>           sTotemCategoryStore;
_extern DBCStorage <VehicleEntry>                 sVehicleStore;
_extern DBCStorage <VehicleSeatEntry>             sVehicleSeatStore;
_extern DBCStorage <WMOAreaTableEntry>            sWMOAreaTableStore;
//_extern DBCStorage <WorldMapAreaEntry>           sWorldMapAreaStore; -- use Zone2MapCoordinates and Map2ZoneCoordinates
_extern DBCStorage <WorldMapOverlayEntry>         sWorldMapOverlayStore;

void LoadDBCStores(const std::string& dataPath);

#endif

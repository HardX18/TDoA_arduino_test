// tdoaEngineInstance.c - holds the tdoa engine state instance


#include "tdoaEngineInstance.h"
#include "tdoaEngine.h"
#include "log.h"
#include "param.h"
#include "static_mem.h"

 tdoaEngineState_t tdoaEngineState;

LOG_GROUP_START(tdoaEngine)
STATS_CNT_RATE_LOG_ADD(stRx, &tdoaEngineState.stats.packetsReceived)
STATS_CNT_RATE_LOG_ADD(stEst, &tdoaEngineState.stats.packetsToEstimator)
STATS_CNT_RATE_LOG_ADD(stTime, &tdoaEngineState.stats.timeIsGood)
STATS_CNT_RATE_LOG_ADD(stFound, &tdoaEngineState.stats.suitableDataFound)
STATS_CNT_RATE_LOG_ADD(stCc, &tdoaEngineState.stats.clockCorrectionCount)
STATS_CNT_RATE_LOG_ADD(stHit, &tdoaEngineState.stats.contextHitCount)
STATS_CNT_RATE_LOG_ADD(stMiss, &tdoaEngineState.stats.contextMissCount)

LOG_ADD(LOG_FLOAT, cc, &tdoaEngineState.stats.clockCorrection)
LOG_ADD(LOG_UINT16, tof, &tdoaEngineState.stats.tof)
LOG_ADD(LOG_FLOAT, tdoa, &tdoaEngineState.stats.tdoa)
LOG_GROUP_STOP(tdoaEngine)


PARAM_GROUP_START(tdoaEngine)
PARAM_ADD(PARAM_UINT8, logId, &tdoaEngineState.stats.newAnchorId)
PARAM_ADD(PARAM_UINT8, logOthrId, &tdoaEngineState.stats.newRemoteAnchorId)

// This variable should not be exposed as a parameter since it is changed from inside the CF FW.
// It only happens when the LPS system mode is changed to TDoA2 or TDoA3 though, and as this is
// not a frequent action, we chose to expose it anyway.
PARAM_ADD(PARAM_UINT8, matchAlgo, &tdoaEngineState.matchingAlgorithm)
PARAM_GROUP_STOP(tdoaEngine)
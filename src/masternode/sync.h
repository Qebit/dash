// Copyright (c) 2014-2021 The Dash Core developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
#ifndef BITCOIN_MASTERNODE_SYNC_H
#define BITCOIN_MASTERNODE_SYNC_H

#include <atomic>
#include <string>

class CMasternodeSync;
class CBlockIndex;
class CConnman;
class CNode;
class CDataStream;

static constexpr int MASTERNODE_SYNC_BLOCKCHAIN      = 1;
static constexpr int MASTERNODE_SYNC_GOVERNANCE      = 4;
static constexpr int MASTERNODE_SYNC_GOVOBJ          = 10;
static constexpr int MASTERNODE_SYNC_GOVOBJ_VOTE     = 11;
static constexpr int MASTERNODE_SYNC_FINISHED        = 999;

static constexpr int MASTERNODE_SYNC_TICK_SECONDS    = 6;
static constexpr int MASTERNODE_SYNC_TIMEOUT_SECONDS = 30; // our blocks are 2.5 minutes so 30 seconds should be fine
static constexpr int MASTERNODE_SYNC_RESET_SECONDS   = 600; // Reset fReachedBestHeader in CMasternodeSync::Reset if UpdateBlockTip hasn't been called for this seconds

extern CMasternodeSync masternodeSync;

//
// CMasternodeSync : Sync masternode assets in stages
//

class CMasternodeSync
{
private:
    // Keep track of current asset
    std::atomic<int> nCurrentAsset{MASTERNODE_SYNC_BLOCKCHAIN};
    // Count peers we've requested the asset from
    std::atomic<int> nTriedPeerCount{0};

    // Time when current masternode asset sync started
    std::atomic<int64_t> nTimeAssetSyncStarted{0};
    // ... last bumped
    std::atomic<int64_t> nTimeLastBumped{0};

    /// Set to true if best header is reached in CMasternodeSync::UpdatedBlockTip
    std::atomic<bool> fReachedBestHeader{false};
    /// Last time UpdateBlockTip has been called
    std::atomic<int64_t> nTimeLastUpdateBlockTip{0};

public:
    CMasternodeSync();

    static void SendGovernanceSyncRequest(CNode* pnode, CConnman& connman);

    bool IsBlockchainSynced() const { return nCurrentAsset > MASTERNODE_SYNC_BLOCKCHAIN; }
    bool IsSynced() const { return nCurrentAsset == MASTERNODE_SYNC_FINISHED; }

    int GetAssetID() const { return nCurrentAsset; }
    int GetAttempt() const { return nTriedPeerCount; }
    void BumpAssetLastTime(const std::string& strFuncName);
    int64_t GetAssetStartTime() const { return nTimeAssetSyncStarted; }
    std::string GetAssetName() const;
    std::string GetSyncStatus() const;

    void Reset(bool fForce = false, bool fNotifyReset = true);
    void SwitchToNextAsset(CConnman& connman);

    void ProcessMessage(CNode* pfrom, const std::string& msg_type, CDataStream& vRecv) const;
    void ProcessTick(CConnman& connman);

    void AcceptedBlockHeader(const CBlockIndex *pindexNew);
    void NotifyHeaderTip(const CBlockIndex *pindexNew, bool fInitialDownload, CConnman& connman);
    void UpdatedBlockTip(const CBlockIndex *pindexNew, bool fInitialDownload, CConnman& connman);

    void DoMaintenance(CConnman &connman);
};

#endif // BITCOIN_MASTERNODE_SYNC_H

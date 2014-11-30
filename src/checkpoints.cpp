// Copyright (c) 2009-2012 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <boost/assign/list_of.hpp> // for 'map_list_of()'
#include <boost/foreach.hpp>

#include "checkpoints.h"

#include "main.h"
#include "uint256.h"

namespace Checkpoints
{
    typedef std::map<int, uint256> MapCheckpoints;

    // How many times we expect transactions after the last checkpoint to
    // be slower. This number is a compromise, as it can't be accurate for
    // every system. When reindexing from a fast disk with a slow CPU, it
    // can be up to 20, while when downloading from a slow network with a
    // fast multicore CPU, it won't be much higher than 1.
    static const double fSigcheckVerificationFactor = 5.0;

    struct CCheckpointData {
        const MapCheckpoints *mapCheckpoints;
        int64 nTimeLastCheckpoint;
        int64 nTransactionsLastCheckpoint;
        double fTransactionsPerDay;
    };

    // What makes a good checkpoint block?
    // + Is surrounded by blocks with reasonable timestamps
   
    // + Contains no strange transactions
    static MapCheckpoints mapCheckpoints =
        boost::assign::map_list_of
        ( 0, uint256("0x000000fcf39055b547e94e610f1008b8046f942bbb730e8b6dfa6232931902db"))
        ( 13000, uint256("0x09f2b9ccb8024bb4eaf3d230945333d2b9418bbb0602d6de8d0f81cc5035136f"))
        ( 19021, uint256("0x050190c7720c393171514350353ec7ac070bf721e79f053e521e0ea64b223d91"))
	( 26012, uint256("0x0384667174cf11623d727993781681f7d47e94a99d85c410d425c2522ba2d928"))
		;

      /////***{
//"hash" : "050190c7720c393171514350353ec7ac070bf721e79f053e521e0ea64b223d91",
//"confirmations" : 881,
//"size" : 676,
//"height" : 19021,
//"version" : 393488,
//"merkleroot" : "8ac1c87021279712f811b7d468ede072e8de2db414295d33a805db397e70b6f6",
//"auxpow" : {
//"size" : 492,
//"coinbasetx" : {
//"txid" : "dd41976c4843a2e405c8f51dc91deffe8988a8597bf837ccf4e016aa7d39263a",
//"version" : 1,
//"locktime" : 0,
//"vin" : [
//{
//"coinbase" : "03cbc00204546321aefabe6d6d780f764280bb761cd7d4acacbd5ec3a2d64c6549ede308c3221333d5037c52c61000000000000000100000004c010000",
//"sequence" : 4294967295
//}
//],
//"vout" : [
//{
//"value" : 25.01193125,
//"n" : 0,
//"scriptPubKey" : {
//"asm" : "OP_DUP OP_HASH160 f31aabe9874f4b59d9043ff5efe75401a3aa88ff OP_EQUALVERIFY OP_CHECKSIG",
//"hex" : "76a914f31aabe9874f4b59d9043ff5efe75401a3aa88ff88ac",
//"reqSigs" : 1,
//"type" : "pubkeyhash",
//"addresses" : [
//"92asrrDL5Xv2iwkveNDj7LWgGsiAK2by3h"
//]
//}
//}
//]
//},
//"coinbaseMerkleBranch" : [
//"dec2490ac01b87968170b78b42ddee777b7c6eb774bf9c470a2eab796bd40894",
//"5d3e8fd681fea8d24d70f0ff1fa6ac2fc79917c2352eae3b0c2ee52aa9ccbbb6",
//"bfef59bd46018c22332d38e001e42163840ef6450c5320e59662b4e9de7b73b0"
//],
//"coinbaseIndex" : 0,
//"chainMerkleBranch" : [
//"000000000000000000000000000000000000000000000000000000000000000d",
//"f95c5404c35a6f6c4f166388125e81691419396103637908a2ab8b2aac1c3cb7",
//"0f61615c7f13657d15d9576c4ca00c423eba9f438f7e7d2eebbe19ca6c092c6d",
//"e12dc5afd260563649cc8cf0827c3902e0a98f6400e160381cf7582fd1e76bed"
//],
//"chainIndex" : 12,
//"parent_block" : {
//"hash" : "0000000000048276b542475e1a8c01ff62e1da0dd04e3c5afdd3a98bb46f1f00",
//"version" : 2,
//"previousblockhash" : "0000000000000b698b80aea693ac17b6b7d7666acc8e8202bbe1ed84d23cdb63",
//"merkleroot" : "ec2d17a551695b9bac0ca84c45853fb02b9fd5a1344a6f48c17e3a5f5f42c2bd",
//"time" : 1415782830,
//"bits" : "1b023313",
//"nonce" : 742148017
//}
//},
//"tx" : [
//"8ac1c87021279712f811b7d468ede072e8de2db414295d33a805db397e70b6f6"
//],
//"time" : 1415782640,
//"nonce" : 0,
//"bits" : "1b04957f",
//"difficulty" : 14296.56228883,
//"previousblockhash" : "9f21667ff1cc6598d91d2bac677a8c63537af709efa80c430203646e4983c97f",
//"nextblockhash" : "972566576299c6368c4c96a5c0db263f1f3612e5eeb73ffde08ad64f31463516"
//}
//****

    static const CCheckpointData data = {
        &mapCheckpoints,
        1417165342, // * UNIX timestamp of last checkpoint block
        999999,     // * total number of transactions between genesis and last checkpoint
                    //   (the tx=... number in the SetBestChain debug.log lines)
        99999     // * estimated number of transactions per day after checkpoint
    };

    static MapCheckpoints mapCheckpointsTestnet = 
        boost::assign::map_list_of
        ( 0, uint256("0x000000fcf39055b547e94e610f1008b8046f942bbb730e8b6dfa6232931902db"))
        ;
    static const CCheckpointData dataTestnet = {
        &mapCheckpointsTestnet,
        1411788333,
        0,
        60000.0
    };

    const CCheckpointData &Checkpoints() {
        if (fTestNet)
            return dataTestnet;
        else
            return data;
    }

    bool CheckBlock(int nHeight, const uint256& hash)
    {
        if (!GetBoolArg("-checkpoints", true))
            return true;

        const MapCheckpoints& checkpoints = *Checkpoints().mapCheckpoints;

        MapCheckpoints::const_iterator i = checkpoints.find(nHeight);
        if (i == checkpoints.end()) return true;
        return hash == i->second;
    }

    // Guess how far we are in the verification process at the given block index
    double GuessVerificationProgress(CBlockIndex *pindex) {
        if (pindex==NULL)
            return 0.0;

        int64 nNow = time(NULL);

        double fWorkBefore = 0.0; // Amount of work done before pindex
        double fWorkAfter = 0.0;  // Amount of work left after pindex (estimated)
        // Work is defined as: 1.0 per transaction before the last checkoint, and
        // fSigcheckVerificationFactor per transaction after.

        const CCheckpointData &data = Checkpoints();

        if (pindex->nChainTx <= data.nTransactionsLastCheckpoint) {
            double nCheapBefore = pindex->nChainTx;
            double nCheapAfter = data.nTransactionsLastCheckpoint - pindex->nChainTx;
            double nExpensiveAfter = (nNow - data.nTimeLastCheckpoint)/86400.0*data.fTransactionsPerDay;
            fWorkBefore = nCheapBefore;
            fWorkAfter = nCheapAfter + nExpensiveAfter*fSigcheckVerificationFactor;
        } else {
            double nCheapBefore = data.nTransactionsLastCheckpoint;
            double nExpensiveBefore = pindex->nChainTx - data.nTransactionsLastCheckpoint;
            double nExpensiveAfter = (nNow - pindex->nTime)/86400.0*data.fTransactionsPerDay;
            fWorkBefore = nCheapBefore + nExpensiveBefore*fSigcheckVerificationFactor;
            fWorkAfter = nExpensiveAfter*fSigcheckVerificationFactor;
        }

        return fWorkBefore / (fWorkBefore + fWorkAfter);
    }

    int GetTotalBlocksEstimate()
    {
        if (!GetBoolArg("-checkpoints", true))
            return 0;

        const MapCheckpoints& checkpoints = *Checkpoints().mapCheckpoints;

        return checkpoints.rbegin()->first;
    }

    CBlockIndex* GetLastCheckpoint(const std::map<uint256, CBlockIndex*>& mapBlockIndex)
    {
        if (!GetBoolArg("-checkpoints", true))
            return NULL;

        const MapCheckpoints& checkpoints = *Checkpoints().mapCheckpoints;

        BOOST_REVERSE_FOREACH(const MapCheckpoints::value_type& i, checkpoints)
        {
            const uint256& hash = i.second;
            std::map<uint256, CBlockIndex*>::const_iterator t = mapBlockIndex.find(hash);
            if (t != mapBlockIndex.end())
                return t->second;
        }
        return NULL;
    }
}

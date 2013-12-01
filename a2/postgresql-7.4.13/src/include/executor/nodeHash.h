/*-------------------------------------------------------------------------
 *
 * nodeHash.h
 *	  prototypes for nodeHash.c
 *
 *
 * Portions Copyright (c) 1996-2003, PostgreSQL Global Development Group
 * Portions Copyright (c) 1994, Regents of the University of California
 *
 * $Id: nodeHash.h,v 1.32 2003/08/04 02:40:13 momjian Exp $
 *
 *-------------------------------------------------------------------------
 */
#ifndef NODEHASH_H
#define NODEHASH_H

/* START NEWCODE */
#define NUM_HASHES 5;
#define BF_FALSE_POSITIVE 0.02;
#define BF_MAX_BITS 600000;
/* END NEWCODE */

#include "nodes/execnodes.h"

extern int	ExecCountSlotsHash(Hash *node);
extern HashState *ExecInitHash(Hash *node, EState *estate);
extern TupleTableSlot *ExecHash(HashState *node);
extern void ExecEndHash(HashState *node);
extern void ExecReScanHash(HashState *node, ExprContext *exprCtxt);

extern HashJoinTable ExecHashTableCreate(Hash *node, List *hashOperators);
extern void ExecHashTableDestroy(HashJoinTable hashtable);
extern void ExecHashTableInsert(HashJoinTable hashtable,
					ExprContext *econtext,
					List *hashkeys);

/* START NEWCODE */
extern BitArray ExecBloomFilterCreate(double est_rows);
extern void ExecBloomFilterDestroy(BitArray bitarray);
extern void ExecBloomFilterInsert(BitArray bitarray,
					ExprContext *econtext,
					List *hashkeys);
extern bool ExecTestMembership(BitArray bitarray,
			 	    ExprContext *econtext,
				    List *hashkeys);
/* END NEWCODE */

extern int ExecHashGetBucket(HashJoinTable hashtable,
				  ExprContext *econtext,
				  List *hashkeys);
extern int	ExecHashGetBatch(int bucketno, HashJoinTable hashtable);
extern HeapTuple ExecScanHashBucket(HashJoinState *hjstate, List *hjclauses,
				   ExprContext *econtext);
extern void ExecHashTableReset(HashJoinTable hashtable, long ntuples);
extern void ExecChooseHashTableSize(double ntuples, int tupwidth,
						int *virtualbuckets,
						int *physicalbuckets,
						int *numbatches);

#endif   /* NODEHASH_H */


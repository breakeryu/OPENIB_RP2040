
#ifndef VSACTION_H_
#define VSACTION_H_

#include "Arduino.h"
#include "src/iono/Iono.h"

#include "src/coder/IonoProject.h"
#include "src/coder/ComPortSystem.h"
#include "src/coder/LogicControlSystem.h"




/*
 * Action Function Prototypes.
 */
void aGetComConfig (void);
void aSendErrorCode (void);
void aSystemReset (void);
void aBleBeginCommunication (void);
void aBleColseComPort (void);
void aBleDateProcessing (void);
void aBeginCommunication (void);
void aDateProcessing (void);
void aRs485ColseComPort (void);



/*
 * Action Function Prototypes.
 */
void aGetLogicConfig (void);
void aInputTransmitterDateUpdate (void);
void aRelayStateUpdate (void);





#endif /* BOARDTEST_H_ */



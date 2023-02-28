#ifndef visualSTATE_LOGICCONTROLSYSTEM_H
#define visualSTATE_LOGICCONTROLSYSTEM_H

/*
 * Id:        LogicControlSystem.h
 *
 * Function:  Contains definitions needed for API functions.
 *
 * This is an automatically generated file. It will be overwritten by the Coder.
 *
 * DO NOT EDIT THE FILE!
 */


#include <stddef.h>


#include "IonoProject.h"


/*
 * SEM Variable Types.
 */
typedef uint8_t   SEM_EVENT_TYPE;
typedef uint8_t   SEM_ACTION_EXPRESSION_TYPE;
typedef uint8_t   SEM_GUARD_EXPRESSION_TYPE;
typedef uint8_t   SEM_EXPLANATION_TYPE;
typedef uint8_t   SEM_STATE_TYPE;
typedef uint8_t   SEM_STATE_MACHINE_TYPE;
typedef uint8_t   SEM_INSTANCE_TYPE;
typedef uint8_t   SEM_RULE_INDEX_TYPE;
typedef uint8_t   SEM_INTERNAL_TYPE;
typedef uint8_t   SEM_SIGNAL_QUEUE_TYPE;
typedef uint8_t   SEM_ACTION_FUNCTION_TYPE;
typedef uint8_t   SEM_EVENT_GROUP_TYPE;
typedef uint8_t   SEM_EGTI_TYPE;
typedef uint8_t   SEM_RULE_TABLE_INDEX_TYPE;


/*
 * Number of Identifiers.
 */
#define VS_NOF_ACTION_FUNCTIONS          3U
#define VS_NOF_EVENTS                    4U
#define VS_NOF_INSTANCES                 1U
#define VS_NOF_STATE_MACHINES            2U
#define VS_NOF_STATES                    4U


/*
 * Undefined State.
 */
#define STATE_UNDEFINED                  255U


/*
 * Undefined Event.
 */
#define EVENT_UNDEFINED                  255U


/*
 * Undefined Event Group.
 */
#define EVENT_GROUP_UNDEFINED            255U


/*
 * Event Termination ID.
 */
#define EVENT_TERMINATION_ID             255U


/*
 * Event Identifier Definitions.
 */
#define SE_RESET 0U
#define eDelay200msForLogicConfig 1U
#define eInputTransmitterDateUpdated 2U
#define eRelayStateUpdated 3U


/*
 * Name        : LogicControlSystemVSInitAll
 *
 * Description : The function is a wrapper to all initialization functions.
 *               The function calls the following functions in the listed
 *               order (provided the specific function exists):
 *                 SEM_Init
 *                 SEM_InitExternalVariables
 *                 SEM_InitInternalVariables
 *                 SEM_InitSignalQueue
 *                 SEM_InitInstances
 *
 * Argument    : None.
 *
 * Return      : None.
 */
void LogicControlSystemVSInitAll (void);


/*
 * Name        : SEM_Init
 *
 * Description : Before calling any other functions this function must be
 *               called to initialize the VS System. In addition it is
 *               possible to call the initialization functions for the
 *               signal queue, internal variables and external variables.
 *
 * Argument    : None.
 *
 * Return      : None.
 */
void LogicControlSystemSEM_Init (void);


/*
 * Name        : LogicControlSystemVSDeduct
 *
 * Description : The function prepares the reception of action expressions,
 *               that can be deduced on the basis of the given event, the
 *               internal current state vector and the rules in the VS
 *               System.
 *               All action expressions are deduced internally in VSDeduct
 *               by continuously calling the function SEM_GetOutput.
 *
 * Argument    : EventNo:
 *                 Event number to be processed.
 *
 *               Variable number of arguments:
 *                 Used if at least one event has a parameter.
 *                 The function call must include one argument for each type
 *                 name declared in the parameter list for each event.
 *                 
 *                 This sample declaration is for an event with three
 *                 parameters:
 *                 
 *                   EventName (uint8_t par1, char par2, int par3)
 *                 
 *                 How to call the VSDeduct function for the event
 *                 EventName:
 *                 
 *                   VSDeduct (EventName, par1, par2, par3);
 *
 * Return      : Completion code:
 *
 *                 SES_ACTIVE:
 *                   The function SEM_Inquiry has been called. All inquired
 *                   events have not been returned by the function
 *                   SEM_GetInput or SEM_GetInputAll. The state/event
 *                   deduction is okay, but the user should not call the
 *                   function SEM_GetInput before the functions
 *                   SEM_NextState or SEM_NextStateChg and SEM_Inquiry have
 *                   been called.
 *
 *                 SES_RANGE_ERR:
 *                   Event is out of range.
 *
 *                 SES_OKAY:
 *                   Success.
 */
VSResult LogicControlSystemVSDeduct (SEM_EVENT_TYPE EventNo);


/*
 * Name        : LogicControlSystemVSElementName
 *
 * Description : The function gets a pointer to the ASCII name of the
 *               specified identifier.
 *               The function must be enabled by its VS Coder option.
 *
 * Argument    : IdentType:
 *                 Must contain the identifier type of the identifier
 *                 number. It can be EVENT_TYPE, STATE_TYPE or ACTION_TYPE.
 *
 *               IdentNo:
 *                 Must contain the index number of an identifier.
 *
 *               Text:
 *                 Must be a pointer to a text string. If the function
 *                 terminates successfully, the text string contains the
 *                 name of the specified identifier.
 *
 * Return      : Completion code:
 *
 *                 SES_RANGE_ERR:
 *                   Identifier number is out of range.
 *
 *                 SES_TYPE_ERR:
 *                   The identifier type is not correct. Remember to include
 *                   the wanted text in the VS System and specify the
 *                   correct identifier type when calling this function.
 *
 *                 SES_OKAY:
 *                   Success.
 */
VSResult LogicControlSystemVSElementName (IdentifierType IdentType, SEM_EXPLANATION_TYPE IdentNo, char const * * Text);


/*
 * Name        : LogicControlSystemVSElementExpl
 *
 * Description : The funciton gets the absolute address of an ASCII
 *               explanation of the specified identifier.
 *               The function must be enabled by its VS Coder option.
 *
 * Argument    : IdentType:
 *                 Must contain the identifier type of the identifier
 *                 number. It can be EVENT_TYPE, STATE_TYPE or ACTION_TYPE.
 *
 *               IdentNo:
 *                 Must contain the index number of an identifier.
 *
 *               Text:
 *                 Must be a pointer to a char pointer. If the function
 *                 terminates successfully, the pointer contains the
 *                 absolute address of the name of the specified identifier.
 *
 * Return      : Completion code:
 *
 *                 SES_RANGE_ERR:
 *                   Identifier number is out of range.
 *
 *                 SES_TYPE_ERR:
 *                   The identifier type is not correct. Remember to include
 *                   the wanted text in the VS System and specify the
 *                   correct identifier type when calling this function.
 *
 *                 SES_OKAY:
 *                   Success.
 */
VSResult LogicControlSystemVSElementExpl (IdentifierType IdentType, SEM_EXPLANATION_TYPE IdentNo, char const * * Text);


/*
 * Action Function Prototypes.
 */
void aGetLogicConfig (void);
void aInputTransmitterDateUpdate (void);
void aRelayStateUpdate (void);


#endif /* ifndef visualSTATE_LOGICCONTROLSYSTEM_H */

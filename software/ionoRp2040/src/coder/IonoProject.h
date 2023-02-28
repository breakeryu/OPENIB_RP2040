#ifndef visualSTATE_IONOPROJECT_H
#define visualSTATE_IONOPROJECT_H

/*
 * Id:        IonoProject.h
 *
 * Function:  Project parts shared between the IAR Visual State systems
 *
 * This is an automatically generated file. It will be overwritten by the Coder.
 *
 * DO NOT EDIT THE FILE!
 */


#include <limits.h>


#include <stdbool.h>


#include <stdint.h>


typedef enum
{

  /*
   * Status code:     SES_OKAY.
   *
   * Explanation:     Function performed successfully.
   *
   * Solution:        None.
   */
  SES_OKAY = 0U,


  /*
   * Status code:     SES_FOUND.
   *
   * Explanation:     The called function has returned an identifier index number.
   *
   * Solution:        Process the returned identifier index number. If the
   *                  function SEM_GetInput or SEM_GetOutput was called, the
   *                  function can be called again to find more events or
   *                  action expressions.
   */
  SES_FOUND = 1U,


  /*
   * Status code:     SES_ACTIVE.
   *
   * Explanation:     The completion code has one of the two expositions:
   *                  1)  A state/event deduction is started, while an event
   *                      inquiry is active. All inquired events have not been
   *                      returned by the function SEM_GetInput.
   *                  2)  An event inquiry is started, while a state/event
   *                      deduction is active. All deduced action expressions 
   *                      have not been returned by the function SEM_GetOutput 
   *                      and the SEM_NextState has not been called in order to 
   *                      complete the state/event deduction.
   *
   * Solution:        The completion code is a warning and perhaps the
   *                  application program should be rewritten. An event inquiry
   *                  and a state/event deduction should not be active at the
   *                  same time.
   */
  SES_ACTIVE = 2U,


  /*
   * Error code:      SES_CONTRADICTION.
   *
   * Explanation:     A contradiction has been detected between two states in a
   *                  state machine.
   *
   * Solution:        Check the VS System.
   */
  SES_CONTRADICTION = 3U,


  /*
   * Error code:      SES_RANGE_ERR.
   *
   * Explanation:     You are making a reference to an identifier that does not
   *                  exist. Note that the first index number is 0. If the 
   *                  VS System has 4 identifiers of the same type and you use a
   *                  function with the variable parameter = 4, the function 
   *                  will return an SES_RANGE_ERR error. In this case the 
   *                  highest variable index number is 3.
   *
   * Solution:        The application program will check the index parameters 
   *                  with one of the following symbols defined in the SEMBDef.h 
   *                  file:
   *
   *                    VS_NOF_EVENTS
   *                    VS_NOF_STATES
   *                    VS_NOF_ACTION_FUNCTIONS
   *                    VS_NOF_STATE_MACHINES
   */
  SES_RANGE_ERR = 4U,


  /*
   * Error code:      SES_TEXT_TOO_LONG.
   *
   * Explanation:     The requested text is longer than the specified maximum length.
   *
   * Solution:        Increase the maximum length.
   */
  SES_TEXT_TOO_LONG = 5U,


  /*
   * Error code:      SES_TYPE_ERR.
   *
   * Explanation:     A text function has been called with the wrong identifier
   *                  type or the specified text is not included in the VS System.
   *
   * Solution:        Use the identifier type symbols (EVENT_TYPE, STATE_TYPE
   *                  or ACTION_TYPE) defined in this file and remember
   *                  to include wanted text in the VS System.
   */
  SES_TYPE_ERR = 6U,


  /*
   * Error code:      SES_EMPTY.
   *
   * Explanation:     No events have been given to the VSDeduct function before
   *                  calling this function.
   *
   * Solution:        Call the VSDeduct function with an event number.
   */
  SES_EMPTY = 7U,


  /*
   * Error code:      SES_BUFFER_OVERFLOW.
   *
   * Explanation:     A destination buffer cannot hold the number of items found.
   *
   * Solution:        Call the function with an extended buffer as destination.
   */
  SES_BUFFER_OVERFLOW = 8U,


  /*
   * Error code:      SES_SIGNAL_QUEUE_FULL.
   *
   * Explanation:     Signal queue is full.
   *
   * Solution:        Increase the maximum signal queue size in the VS System or
   *                  via the VS Coder signal queue size option.
   */
  SES_SIGNAL_QUEUE_FULL = 9U,


  /*
   * Error code:      SES_NOT_INITIALIZED.
   *
   * Explanation:     The system has not been initialized.
   *
   * Solution:        Call the initialization function for the VS System.
   */
  SES_NOT_INITIALIZED = 10U
} VSResult;


/* Identifier types, used when getting texts and explanations. */
typedef enum { EVENT_TYPE = 0U, STATE_TYPE = 1U, ACTION_TYPE = 2U } IdentifierType;


char const *VSGetSignature (void);


#endif /* ifndef visualSTATE_IONOPROJECT_H */

/* vim:ts=4:sw=4:expandtab
 * (No tabs, indent level is 4 spaces) */
/*****************************************************************************
 * File:            fm10000_api_an_state_machines.h
 * Creation Date:   April 4th, 2013
 * Description:     Header file for the auto-negotiation state machines
 * 
 *                  ------------------------------------------------------
 *                  THIS FILE IS AUTO-GENERATED BY THE BUILD SYSTEM, DO
 *                  NOT MODIFY THIS FILE.  MODIFY THE FOLLOWING INSTEAD
 *                  ------------------------------------------------------
 * 
 *                  1) fm10000_api_an_state_machine.xml
 *                  2) templates/fm10000_api_an_state_machine.h
 *
 * Copyright (c) 2007 - 2015, Intel Corporation
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright notice,
 *       this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of Intel Corporation nor the names of its contributors
 *       may be used to endorse or promote products derived from this software
 *       without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *****************************************************************************/

#ifndef __FM_FM10000_API_AN_STATE_MACHINES_H
#define __FM_FM10000_API_AN_STATE_MACHINES_H


/* declaration of the auto-negotiation state machine types */
#define FM10000_CLAUSE73_AN_STATE_MACHINE 401
#define FM10000_CLAUSE37_AN_STATE_MACHINE 400


/* declaration of auto-negotiation states */
typedef enum
{
    FM10000_AN_STATE_DISABLED = 0,
    FM10000_AN_STATE_ENABLED,
    FM10000_AN_STATE_RESTART,
    FM10000_AN_STATE_DISABLE_LINK_OK,
    FM10000_AN_STATE_ABILITY_DETECT,
    FM10000_AN_STATE_ACK_DETECT,
    FM10000_AN_STATE_COMPLETE_ACK,
    FM10000_AN_STATE_IDLE_DETECT,
    FM10000_AN_STATE_NEXT_PAGE_WAIT,
    FM10000_AN_STATE_TRANSMIT_DISABLE,
    FM10000_AN_STATE_GOOD_CHECK,
    FM10000_AN_STATE_GOOD,
    FM10000_AN_STATE_LINK_OK,
    FM10000_AN_STATE_MAX

} fm10000_anSmStates;

extern fm_text fm10000AnStatesMap[FM10000_AN_STATE_MAX];


/* declaration of auto-negotiation events */
typedef enum
{
    FM10000_AN_EVENT_START_REQ = 0,
    FM10000_AN_EVENT_STOP_REQ,
    FM10000_AN_EVENT_ENABLE_IND,
    FM10000_AN_EVENT_RESTART_IND,
    FM10000_AN_EVENT_DISABLE_LINK_OK_IND,
    FM10000_AN_EVENT_ABILITY_DETECT_IND,
    FM10000_AN_EVENT_ACK_DETECT_IND,
    FM10000_AN_EVENT_COMPLETE_ACK_IND,
    FM10000_AN_EVENT_NEXT_PAGE_WAIT_IND,
    FM10000_AN_EVENT_IDLE_DETECT_IND,
    FM10000_AN_EVENT_LINK_OK_IND,
    FM10000_AN_EVENT_TRANSMIT_DISABLE_IND,
    FM10000_AN_EVENT_GOOD_CHECK_IND,
    FM10000_AN_EVENT_GOOD_IND,
    FM10000_AN_EVENT_POLLING_TIMER_EXP_IND,
    FM10000_AN_EVENT_MAX

} fm10000_anSmEvents;

extern fm_text fm10000AnEventsMap[FM10000_AN_EVENT_MAX];

/* declaration of external counterparts of action callbacks */
fm_status fm10000TakeRegLock( fm_smEventInfo *eventInfo, void *userInfo );
fm_status fm10000DropRegLock( fm_smEventInfo *eventInfo, void *userInfo );
fm_status fm10000EnableAn( fm_smEventInfo *eventInfo, void *userInfo );
fm_status fm10000DisableAn( fm_smEventInfo *eventInfo, void *userInfo );
fm_status fm10000EnableAnInterrupts( fm_smEventInfo *eventInfo, void *userInfo );
fm_status fm10000DisableAnInterrupts( fm_smEventInfo *eventInfo, void *userInfo );
fm_status fm10000ConfigureBasePage( fm_smEventInfo *eventInfo, void *userInfo );
fm_status fm10000ConfigureNextPages( fm_smEventInfo *eventInfo, void *userInfo );
fm_status fm10000NotifyApiAutonegCompleteOrFault( fm_smEventInfo *eventInfo, void *userInfo );
fm_status fm10000NotifyApiAutonegFailed( fm_smEventInfo *eventInfo, void *userInfo );
fm_status fm10000NotifyApiAutonegStarted( fm_smEventInfo *eventInfo, void *userInfo );
fm_status fm10000ConfigureAnTimers( fm_smEventInfo *eventInfo, void *userInfo );
fm_status fm10000NotifyPortAutonegComplete( fm_smEventInfo *eventInfo, void *userInfo );
fm_status fm10000NotifyPortAutonegRestarted( fm_smEventInfo *eventInfo, void *userInfo );
fm_status fm10000DoAbilityMatch( fm_smEventInfo *eventInfo, void *userInfo );
fm_status fm10000StartAnPollingTimer( fm_smEventInfo *eventInfo, void *userInfo );
fm_status fm10000StopAnPollingTimer( fm_smEventInfo *eventInfo, void *userInfo );
fm_status fm10000PerformAnPortStatusValidation( fm_smEventInfo *eventInfo, void *userInfo );



/* declaration of external counterparts of condition callbacks */
fm_status fm10000Dummy( fm_smEventInfo *eventInfo, void *userInfo, fm_int *nextState );



/* declaration of the log callback functions, if any */
fm_status fm10000LogAnStateTransition( fm_smTransitionRecord *record );

/* declaration of registration functions for autoneg state machine types */
fm_status fm10000RegisterClause73AnStateMachine( void );
fm_status fm10000RegisterClause37AnStateMachine( void );

#endif /* __FM_FM10000_API_AN_STATE_MACHINES_H */

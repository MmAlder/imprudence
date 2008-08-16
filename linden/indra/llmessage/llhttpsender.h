/** 
 * @file llhttpsender.h
 * @brief Abstracts details of sending messages via HTTP.
 *
 * Copyright (c) 2007-2007, Linden Research, Inc.
 * 
 * Second Life Viewer Source Code
 * The source code in this file ("Source Code") is provided by Linden Lab
 * to you under the terms of the GNU General Public License, version 2.0
 * ("GPL"), unless you have obtained a separate licensing agreement
 * ("Other License"), formally executed by you and Linden Lab.  Terms of
 * the GPL can be found in doc/GPL-license.txt in this distribution, or
 * online at http://secondlife.com/developers/opensource/gplv2
 * 
 * There are special exceptions to the terms and conditions of the GPL as
 * it is applied to this Source Code. View the full text of the exception
 * in the file doc/FLOSS-exception.txt in this software distribution, or
 * online at http://secondlife.com/developers/opensource/flossexception
 * 
 * By copying, modifying or distributing this software, you acknowledge
 * that you have read and understood your obligations described above,
 * and agree to abide by those obligations.
 * 
 * ALL LINDEN LAB SOURCE CODE IS PROVIDED "AS IS." LINDEN LAB MAKES NO
 * WARRANTIES, EXPRESS, IMPLIED OR OTHERWISE, REGARDING ITS ACCURACY,
 * COMPLETENESS OR PERFORMANCE.
 */

#ifndef LL_HTTP_SENDER_H
#define LL_HTTP_SENDER_H

#include "llhttpclient.h"

class LLHost;
class LLSD;

class LLHTTPSender
{
 public:

	virtual ~LLHTTPSender();

	/** @brief Send message to host with body, call response when done */ 
	virtual void send(const LLHost& host, 
					  const char* message, const LLSD& body, 
					  LLHTTPClient::ResponderPtr response) const;

	/** @brief Set sender for host, takes ownership of sender. */
	static void setSender(const LLHost& host, LLHTTPSender* sender);

	/** @brief Get sender for host, retains ownership of returned sender. */
	static const LLHTTPSender& getSender(const LLHost& host);
	
	/** @brief Clear sender for host. */
	static void clearSender(const LLHost& host);

	/** @brief Set default sender, takes ownership of sender. */
	static void setDefaultSender(LLHTTPSender* sender);
};

#endif // LL_HTTP_SENDER_H

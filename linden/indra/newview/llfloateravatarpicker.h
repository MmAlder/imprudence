/** 
 * @file llfloateravatarpicker.h
 * @brief was llavatarpicker.h
 *
 * $LicenseInfo:firstyear=2003&license=viewergpl$
 * 
 * Copyright (c) 2003-2009, Linden Research, Inc.
 * 
 * Second Life Viewer Source Code
 * The source code in this file ("Source Code") is provided by Linden Lab
 * to you under the terms of the GNU General Public License, version 2.0
 * ("GPL"), unless you have obtained a separate licensing agreement
 * ("Other License"), formally executed by you and Linden Lab.  Terms of
 * the GPL can be found in doc/GPL-license.txt in this distribution, or
 * online at http://secondlifegrid.net/programs/open_source/licensing/gplv2
 * 
 * There are special exceptions to the terms and conditions of the GPL as
 * it is applied to this Source Code. View the full text of the exception
 * in the file doc/FLOSS-exception.txt in this software distribution, or
 * online at http://secondlifegrid.net/programs/open_source/licensing/flossexception
 * 
 * By copying, modifying or distributing this software, you acknowledge
 * that you have read and understood your obligations described above,
 * and agree to abide by those obligations.
 * 
 * ALL LINDEN LAB SOURCE CODE IS PROVIDED "AS IS." LINDEN LAB MAKES NO
 * WARRANTIES, EXPRESS, IMPLIED OR OTHERWISE, REGARDING ITS ACCURACY,
 * COMPLETENESS OR PERFORMANCE.
 * $/LicenseInfo$
 */

#ifndef LLFLOATERAVATARPICKER_H
#define LLFLOATERAVATARPICKER_H

#include "llfloater.h"

#include <vector>


class LLFloaterAvatarPicker : public LLFloater
{
public:
	// Call this to select an avatar.
	// The callback function will be called with an avatar name and UUID.
	typedef void(*callback_t)(const std::vector<std::string>&, const std::vector<LLUUID>&, void*);
	static LLFloaterAvatarPicker* show(callback_t callback, 
									   void* userdata,
									   BOOL allow_multiple = FALSE,
									   BOOL closeOnSelect = FALSE);
	virtual	BOOL postBuild();

	static void processAvatarPickerReply(class LLMessageSystem* msg, void**);

private:

	static void editKeystroke(class LLLineEditor* caller, void* user_data);

	static void onBtnFind(void* userdata);
	static void onBtnSelect(void* userdata);
	static void onBtnRefresh(void* userdata);
	static void onRangeAdjust(LLUICtrl* source, void* data);
	static void onBtnClose(void* userdata);
	static void onList(class LLUICtrl* ctrl, void* userdata);
	static void onTabChanged(void* userdata, bool from_click);
	
		   void doCallingCardSelectionChange(const std::deque<class LLFolderViewItem*> &items, BOOL user_action, void* data);
	static void onCallingCardSelectionChange(const std::deque<class LLFolderViewItem*> &items, BOOL user_action, void* data);

	void populateNearMe();
	BOOL visibleItemsSelected() const; // Returns true if any items in the current tab are selected.

	void find();
	void setAllowMultiple(BOOL allow_multiple);

	virtual void draw();
	virtual BOOL handleKeyHere(KEY key, MASK mask);

	std::vector<LLUUID>				mSelectedInventoryAvatarIDs;
	std::vector<std::string>		mSelectedInventoryAvatarNames;
	LLUUID				mQueryID;
	BOOL				mResultsReturned;
	BOOL				mNearMeListComplete;
	BOOL				mCloseOnSelect;

	void (*mCallback)(const std::vector<std::string>& name, const std::vector<LLUUID>& id, void* userdata);
	void* mCallbackUserdata;

	static LLFloaterAvatarPicker* sInstance;

	// do not call these directly
	LLFloaterAvatarPicker();
	virtual ~LLFloaterAvatarPicker();
};

#endif

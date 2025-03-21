/*
	SourcePawn is Copyright (C) 2006-2008 AlliedModders LLC.  All rights reserved.
	SourceMod is Copyright (C) 2006-2008 AlliedModders LLC.  All rights reserved.
	Pawn and SMALL are Copyright (C) 1997-2008 ITB CompuPhase.
	Source is Copyright (C) Valve Corporation.
	All trademarks are property of their respective owners.

	This program is free software: you can redistribute it and/or modify it
	under the terms of the GNU General Public License as published by the
	Free Software Foundation, either version 3 of the License, or (at your
	option) any later version.

	This program is distributed in the hope that it will be useful, but
	WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
	General Public License for more details.

	You should have received a copy of the GNU General Public License along
	with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#if defined  _l4d2_mixmap_included_
 #endinput
#endif
#define _l4d2_mixmap_included_

/**
 * @brief Returns if mix map is active
 * 
 * @return 			True if mix map is active, false otherwise
 */
native bool l4d2_mixmap_IsActive();

/**
 * @brief Get the next map name for mix map
 *
 * @param buffer	String to write map name, empty if there is no next mix map
 * @param maxlength	Max length of buffer
 * 
 * @noreturn
 */
native void l4d2_mixmap_GetNextMap(char[] buffer, int maxlength);

/**
 * @brief Called when plugin is about to load first mix map
 * @note Right before loading first map
 * 
 * @param iMapCount 		Total Mix Map Count
 * @param sMapName 			First Mix Map Name
 */
forward void OnCMTStart(int iMapCount, const char[] sMapName);

/**
 * @brief Called when mix map is loaded and what is the next mix map
 * @note Right after the map is loaded
 * 
 * @param sMapName 			Map name of next mix map, empty if there is no next mix map
 */
forward void OnCMTLoaded(const char[] sMapName);

/**
 * @brief Called when last map is played and mixmap is finished
 * @note Right after round ends or final wins
 * 
 */
forward void OnCMTEnd();


public SharedPlugin __pl_l4d2_mixmap =
{
	name = "l4d2_mixmap",
	file = "l4d2_mixmap.smx",
#if defined REQUIRE_PLUGIN
	required = 1,
#else
	required = 0,
#endif
};

#if !defined REQUIRE_PLUGIN
public void __pl_l4d2_mixmap_SetNTVOptional()
{
	MarkNativeAsOptional("l4d2_mixmap_IsActive");
	MarkNativeAsOptional("l4d2_mixmap_GetNextMap");
}
#endif
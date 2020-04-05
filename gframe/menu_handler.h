#ifndef MENU_HANDLER_H
#define MENU_HANDLER_H

#include "config.h"
#include <IEventReceiver.h>

namespace ygo {

class MenuHandler: public irr::IEventReceiver {
public:
	virtual bool OnEvent(const irr::SEvent& event);
	int prev_operation;
	int prev_sel;

};

// These are passed to Irrlicht constructors as IDs and useful for identifying spawned GUI events
enum GUI {
	BUTTON_LAN_MODE,
	BUTTON_SINGLE_MODE,
	BUTTON_REPLAY_MODE,
	BUTTON_TEST_MODE,
	BUTTON_DECK_EDIT,
	BUTTON_MODE_EXIT,
	LISTBOX_LAN_HOST,
	BUTTON_JOIN_HOST,
	BUTTON_JOIN_CANCEL,
	BUTTON_CREATE_HOST,
	BUTTON_HOST_CONFIRM,
	BUTTON_HOST_CANCEL,
	BUTTON_LAN_REFRESH,
	BUTTON_RULE_CARDS,
	BUTTON_RULE_OK,
	BUTTON_CUSTOM_RULE,
	BUTTON_HP_DUELIST,
	BUTTON_HP_OBSERVER,
	BUTTON_HP_START,
	BUTTON_HP_CANCEL,
	BUTTON_HP_KICK,
	CHECKBOX_HP_READY,
	BUTTON_HP_READY,
	BUTTON_HP_NOTREADY,
	COMBOBOX_HOST_LFLIST,
	COMBOBOX_DUEL_RULE,
	BUTTON_CUSTOM_RULE_OK,
	LISTBOX_REPLAY_LIST,
	BUTTON_LOAD_REPLAY,
	BUTTON_CANCEL_REPLAY,
	BUTTON_DELETE_REPLAY,
	BUTTON_RENAME_REPLAY,
	BUTTON_EXPORT_DECK,
	EDITBOX_TEAM_COUNT,
	EDITBOX_NUMERIC,
	BUTTON_HP_AI_TOGGLE,
	BUTTON_BOT_ADD,
	EDITBOX_CHAT,
	EDITBOX_PORT_BOX,
	COMBOBOX_BOT_DECK,
	EDITBOX_NICKNAME,
	BUTTON_MSG_OK,
	BUTTON_YES,
	BUTTON_NO,
	BUTTON_HAND1,
	BUTTON_HAND2,
	BUTTON_HAND3,
	BUTTON_FIRST,
	BUTTON_SECOND,
	BUTTON_POS_AU,
	BUTTON_POS_AD,
	BUTTON_POS_DU,
	BUTTON_POS_DD,
	BUTTON_OPTION_PREV,
	BUTTON_OPTION_NEXT,
	BUTTON_OPTION_OK,
	BUTTON_OPTION_0,
	BUTTON_OPTION_1,
	BUTTON_OPTION_2,
	BUTTON_OPTION_3,
	BUTTON_OPTION_4,
	SCROLL_OPTION_SELECT,
	BUTTON_CARD_0,
	BUTTON_CARD_1,
	BUTTON_CARD_2,
	BUTTON_CARD_3,
	BUTTON_CARD_4,
	SCROLL_CARD_SELECT,
	BUTTON_CARD_SEL_OK,
	TEXT_CARD_LIST_TIP,
	BUTTON_CMD_ACTIVATE,
	BUTTON_CMD_SUMMON,
	BUTTON_CMD_SPSUMMON,
	BUTTON_CMD_MSET,
	BUTTON_CMD_SSET,
	BUTTON_CMD_REPOS,
	BUTTON_CMD_ATTACK,
	BUTTON_CMD_SHOWLIST,
	BUTTON_CMD_SHUFFLE,
	BUTTON_CMD_RESET,
	BUTTON_ANNUMBER_OK,
	BUTTON_ANCARD_OK,
	EDITBOX_ANCARD,
	LISTBOX_ANCARD,
	CHECK_ATTRIBUTE,
	CHECK_RACE,
	BUTTON_BP,
	BUTTON_M2,
	BUTTON_EP,
	BUTTON_LEAVE_GAME,
	BUTTON_CHAIN_IGNORE,
	BUTTON_CHAIN_ALWAYS,
	BUTTON_CHAIN_WHENAVAIL,
	BUTTON_CANCEL_OR_FINISH,
	BUTTON_RESTART_SINGLE,
	BUTTON_CLEAR_LOG,
	LISTBOX_LOG,
	BUTTON_CLEAR_CHAT,
	BUTTON_EXPAND_INFOBOX,
	BUTTON_REPO_CHANGELOG,
	BUTTON_REPO_CHANGELOG_EXIT,
	BUTTON_REPO_CHANGELOG_EXPAND,
	BUTTON_DISPLAY_0,
	BUTTON_DISPLAY_1,
	BUTTON_DISPLAY_2,
	BUTTON_DISPLAY_3,
	BUTTON_DISPLAY_4,
	SCROLL_CARD_DISPLAY,
	BUTTON_CARD_DISP_OK,
	EDITBOX_DECK_NAME,
	BUTTON_CATEGORY_OK,
	COMBOBOX_DBLFLIST,
	COMBOBOX_DBDECKS,
	BUTTON_CLEAR_DECK,
	BUTTON_SAVE_DECK,
	BUTTON_SAVE_DECK_AS,
	BUTTON_DELETE_DECK,
	BUTTON_RENAME_DECK,
	BUTTON_SIDE_RELOAD,
	BUTTON_SORT_DECK,
	BUTTON_SIDE_OK,
	BUTTON_SHUFFLE_DECK,
	COMBOBOX_MAINTYPE,
	COMBOBOX_SECONDTYPE,
	BUTTON_EFFECT_FILTER,
	BUTTON_START_FILTER,
	SCROLL_FILTER,
	EDITBOX_ATTACK,
	EDITBOX_DEFENSE,
	EDITBOX_STAR,
	EDITBOX_SCALE,
	EDITBOX_KEYWORD,
	BUTTON_CLEAR_FILTER,
	BUTTON_HAND_TEST,
	COMBOBOX_OTHER_FILT,
	BUTTON_REPLAY_START,
	BUTTON_REPLAY_PAUSE,
	BUTTON_REPLAY_STEP,
	BUTTON_REPLAY_UNDO,
	BUTTON_REPLAY_EXIT,
	BUTTON_REPLAY_SWAP,
	EDITBOX_REPLAY_NAME,
	BUTTON_REPLAY_SAVE,
	BUTTON_REPLAY_CANCEL,
	LISTBOX_SINGLEPLAY_LIST,
	BUTTON_LOAD_SINGLEPLAY,
	BUTTON_CANCEL_SINGLEPLAY,
	CHECKBOX_EXTRA_RULE,
	CHECKBOX_ENABLE_MUSIC,
	CHECKBOX_ENABLE_SOUND,
	SCROLL_MUSIC_VOLUME,
	SCROLL_SOUND_VOLUME,
	CHECKBOX_SHOW_ANIME,
	CHECKBOX_QUICK_ANIMATION,
	COMBOBOX_SORTTYPE,
	CHECKBOX_CHAIN_BUTTONS,
	COMBOBOX_CURRENT_SKIN,
	BUTTON_RELOAD_SKIN,
	COMBOBOX_CURRENT_LOCALE,
	BUTTON_SHOW_SETTINGS,
	BUTTON_APPLY_RESTART,

	CHECKBOX_SHOW_FPS,
	CHECKBOX_FULLSCREEN,
	CHECKBOX_SCALE_BACKGROUND,
	CHECKBOX_ACCURATE_BACKGROUND_RESIZE,
	CHECKBOX_HIDE_ARCHETYPES,
	CHECKBOX_HIDE_PASSCODE_SCOPE,
	CHECKBOX_DRAW_FIELD_SPELLS,
	CHECKBOX_FILTER_BOT,
	BUTTON_FPS_CAP,
	COMBOBOX_CORE_LOG_OUTPUT,
	CHECKBOX_SHOW_SCOPE_LABEL,
	CHECKBOX_SAVE_HAND_TEST_REPLAY,

	BUTTON_MARKS_FILTER,
	BUTTON_MARKERS_OK,

	CHECKBOX_OBSOLETE,
	CHECKBOX_DRAW,
	CHECKBOX_FIELD,
	CHECKBOX_PZONE,
	CHECKBOX_SEPARATE_PZONE,
	CHECKBOX_EMZONE,
	CHECKBOX_FSX_NOEMZONE,
	CHECKBOX_TRAPMON_ZONES,
	CHECKBOX_FACEDOWN_ED_TRIGGER,
	LOCATION_TRIGGER_CHECK,
	OLD_NEGATION_SUMMON_OPT,
	OLD_NEGATION_SUMMON_COUNT,
	NO_STANDBY_PHASE,
	NO_MAIN_PHASE2,
	THREE_COLUMN_FIELD,
	DRAW_UNTIL_5,
	NO_HAND_LIMIT,
	NO_NORMAL_SUMMON_LIMIT,
	INVERTED_PRIORITY,

	TABLE_ROOMLIST,
	BUTTON_ROOMPASSWORD_OK,
	BUTTON_JOIN_HOST2,
	BUTTON_JOIN_CANCEL2,
	BUTTON_LAN_REFRESH2,
	CHECK_LINUX_UNRANKED,
	SERVER_CHOICE,
	BUTTON_CREATE_HOST2,
	CB_FILTER_ALLOWED_CARDS,
	CB_FILTER_MATCH_MODE,
	CB_FILTER_BANLIST,
	BUTTON_FILTER_RELAY,
	EDIT_ONLINE_ROOM_NAME,
	CHECK_SHOW_LOCKED_ROOMS,
	CHECK_SHOW_ACTIVE_ROOMS,
	BUTTON_ROOMPASSWORD_CANCEL,
	BUTTON_ONLINE_MULTIPLAYER // first button on main menu
};

}

#endif //MENU_HANDLER_H

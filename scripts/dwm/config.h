/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 0;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "monospace:size=10" };
static const char dmenufont[]       = "monospace:size=10";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
};

/* tagging */
static const char *tags[] = { "Qutebrowser", "Dmacs", "Anki", "Alacritty", "Okular", "Pavucontrol", "Krita", "Chromium", "Sleep", "Definition", "Email", "Torrent" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "mpv",      "piano",    NULL,       1,            0,           0 },
	{ "mpv",      "nightcore",NULL,       1 << 1,       0,           0 },
	{ "mpv",      "reading",  NULL,       1 << 2,       0,           0 },
	{ "mpv",      "study",    NULL,       1 << 3,       0,           0 },
	{ "Emacs",    NULL,       NULL,       1 << 1,       0,           1 },
	{ "Anki",     NULL,       NULL,       1 << 2,       0,           1 },
	{ "Alacritty","Alacritty",NULL,       1 << 3,       0,           1 },
	{ "okular",   NULL,       NULL,       1 << 4,       0,           1 },
	{ "Pavucontrol",NULL,     NULL,       1 << 5,       0,           1 },
	{ "krita",    NULL,       NULL,       1 << 6,       0,           1 },
	{ "Chromium", NULL,       NULL,       1 << 7,       0,           1 },
	{ "qutebrowser","definition",NULL,    1 << 9,       0,           1 },
	{ "thunderbird",NULL,     NULL,       1 << 10,      0,           1 },
	{ "qBittorrent",NULL,     NULL,       1 << 11,      0,           1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      tag,            {.ui = 1 << TAG} }, \
	//{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *dmenucmd[] = { "dmenu_run", "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *termcmd[]  = { "alacritty", NULL };

static const Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY|ShiftMask,             XK_h,      musicchannel,   {.ch = 1 } },
	{ MODKEY|ShiftMask,             XK_j,      musicchannel,   {.ch = 2 } },
	{ MODKEY|ShiftMask,             XK_k,      musicchannel,   {.ch = 3 } },
	{ MODKEY|ShiftMask,             XK_l,      musicchannel,   {.ch = 4 } },

	/* { MODKEY|ShiftMask,             XK_e,      spawn,          SHCMD("qutebrowser") }, */
	/* { MODKEY|ShiftMask,             XK_d,      spawn,          SHCMD("emacsclient -c -a 'emacs'") }, */
	/* { MODKEY|ShiftMask,             XK_a,      spawn,          SHCMD("anki") }, */
	/* { MODKEY|ShiftMask,             XK_b,      spawn,          SHCMD("thunderbird") }, */
	/* { MODKEY|ShiftMask,             XK_t,      spawn,          SHCMD("qbittorrent") }, */
	/* { MODKEY|ShiftMask,             XK_v,      spawn,          SHCMD("pavucontrol") }, */

	{ MODKEY|ShiftMask,             XK_x,      spawn,          SHCMD("speedcrunch") },

	{ MODKEY|ShiftMask,             XK_s,      spawn,          SHCMD("maim -su | xclip -selection clipboard -t image/png") },
	{ MODKEY|ShiftMask,             XK_r,      spawn,          SHCMD("alacritty --class dwm,Alacritty -e sudo reboot") },
	{ MODKEY|ShiftMask,             XK_Escape, spawn,          SHCMD("alacritty --class dwm,Alacritty -e sudo shutdown now") },
	{ MODKEY|ShiftMask,             XK_grave,  spawn,          SHCMD("alacritty --class dwm,Alacritty -e sudo systemctl suspend") },
	{ MODKEY|ShiftMask,             XK_u,      spawn,          SHCMD("alacritty --class dwm,Alacritty -e sudo pacman -Syu") },
	{ MODKEY|ShiftMask,             XK_y,      spawn,          SHCMD("~/scripts/runmpv") },
	{ MODKEY|ShiftMask,             XK_o,      spawn,          SHCMD("yt-dlp $(xclip -o -selection clipboard)") },
	{ MODKEY|ShiftMask,             XK_p,      spawn,          SHCMD("mpv $(xclip -o -selection clipboard)") },
	/* { MODKEY|ShiftMask,             XK_w,      spawn,          SHCMD("vboxmanage startvm 'Windows 10'") }, */
	/* { MODKEY|ShiftMask,             XK_KP_0,   spawn,          SHCMD("mpv --shuffle -fs --loop-playlist --force-window media/Nightcore") }, */
	/* { MODKEY|ShiftMask,             XK_KP_1,   spawn,          SHCMD("mpv --shuffle -fs --loop-playlist --force-window media/piano") }, */
	/* { MODKEY|ShiftMask,             XK_KP_2,   spawn,          SHCMD("mpv --shuffle -fs --loop-playlist --force-window media/reading") }, */
	/* { MODKEY|ShiftMask,             XK_KP_3,   spawn,          SHCMD("mpv --shuffle -fs --loop-playlist --force-window media/study") }, */
	{ MODKEY,                       XK_q,      realshit,       {0} },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	/* { MODKEY,                       XK_i,      incnmaster,     {.i = +1 } }, */
	/* { MODKEY,                       XK_d,      incnmaster,     {.i = -1 } }, */
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	/* { MODKEY,                       XK_Tab,    view,           {0} }, */
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	/* { MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} }, */
	/* { MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} }, */
	/* { MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} }, */
	/* { MODKEY,                       XK_space,  setlayout,      {0} }, */
	/* { MODKEY|ShiftMask,             XK_space,  togglefloating, {0} }, */
	/* { MODKEY,                       XK_0,      view,           {.ui = ~0 } }, */
	/* { MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } }, */
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },

	TAGKEYS(                        XK_e,                      0) // qutebrowser
	TAGKEYS(                        XK_d,                      1) // dmacs
	TAGKEYS(                        XK_a,                      2) // anki
	TAGKEYS(                        XK_c,                      3) // alacritty
	TAGKEYS(                        XK_o,                      4) // okular
	TAGKEYS(                        XK_v,                      5) // pavucontrol
	TAGKEYS(                        XK_r,                      6) // krita
	TAGKEYS(                        XK_g,                      7) // chromium google translate
	TAGKEYS(                        XK_9,                      8) // empty tag
	TAGKEYS(                        XK_w,                      9) // definition
	TAGKEYS(                        XK_z,                      10) // email
	TAGKEYS(                        XK_t,                      11) // torrent

	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
	{ MODKEY|ShiftMask,             XK_BackSpace,spawn,        SHCMD("kill -9 -1") },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};


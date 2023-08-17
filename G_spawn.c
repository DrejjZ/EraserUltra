
#include "g_local.h"
#include "bot_procs.h"
#include "p_trail.h"

typedef struct
{
	char	*name;
	void	(*spawn)(edict_t *ent);
} spawn_t;


void SP_item_health (edict_t *self);
void SP_item_health_small (edict_t *self);
void SP_item_health_large (edict_t *self);
void SP_item_health_mega (edict_t *self);

void SP_info_player_start (edict_t *ent);
void SP_info_player_deathmatch (edict_t *ent);
void SP_info_player_coop (edict_t *ent);
void SP_info_player_intermission (edict_t *ent);

void SP_func_plat (edict_t *ent);
void SP_func_rotating (edict_t *ent);
void SP_func_button (edict_t *ent);
void SP_func_door (edict_t *ent);
void SP_func_door_secret (edict_t *ent);
void SP_func_door_rotating (edict_t *ent);
void SP_func_water (edict_t *ent);
void SP_func_train (edict_t *ent);
void SP_func_conveyor (edict_t *self);
void SP_func_wall (edict_t *self);
void SP_func_object (edict_t *self);
void SP_func_explosive (edict_t *self);
void SP_func_timer (edict_t *self);
void SP_func_areaportal (edict_t *ent);
void SP_func_clock (edict_t *ent);
void SP_func_killbox (edict_t *ent);

void SP_trigger_always (edict_t *ent);
void SP_trigger_once (edict_t *ent);
void SP_trigger_multiple (edict_t *ent);
void SP_trigger_relay (edict_t *ent);
void SP_trigger_push (edict_t *ent);
void SP_trigger_hurt (edict_t *ent);
void SP_trigger_key (edict_t *ent);
void SP_trigger_counter (edict_t *ent);
void SP_trigger_elevator (edict_t *ent);
void SP_trigger_gravity (edict_t *ent);
void SP_trigger_monsterjump (edict_t *ent);

void SP_target_temp_entity (edict_t *ent);
void SP_target_speaker (edict_t *ent);
void SP_target_explosion (edict_t *ent);
void SP_target_changelevel (edict_t *ent);
void SP_target_secret (edict_t *ent);
void SP_target_goal (edict_t *ent);
void SP_target_splash (edict_t *ent);
void SP_target_spawner (edict_t *ent);
void SP_target_blaster (edict_t *ent);
void SP_target_crosslevel_trigger (edict_t *ent);
void SP_target_crosslevel_target (edict_t *ent);
void SP_target_laser (edict_t *self);
void SP_target_help (edict_t *ent);
void SP_target_lightramp (edict_t *self);
void SP_target_earthquake (edict_t *ent);
void SP_target_character (edict_t *ent);
void SP_target_string (edict_t *ent);

void SP_worldspawn (edict_t *ent);
void SP_viewthing (edict_t *ent);

void SP_light (edict_t *self);
void SP_light_mine1 (edict_t *ent);
void SP_light_mine2 (edict_t *ent);
void SP_info_null (edict_t *self);
void SP_info_notnull (edict_t *self);
void SP_path_corner (edict_t *self);
void SP_point_combat (edict_t *self);

void SP_misc_explobox (edict_t *self);
void SP_misc_banner (edict_t *self);
void SP_misc_satellite_dish (edict_t *self);
void SP_misc_actor (edict_t *self);
void SP_misc_gib_arm (edict_t *self);
void SP_misc_gib_leg (edict_t *self);
void SP_misc_gib_head (edict_t *self);
void SP_misc_insane (edict_t *self);
void SP_misc_deadsoldier (edict_t *self);
void SP_misc_viper (edict_t *self);
void SP_misc_viper_bomb (edict_t *self);
void SP_misc_bigviper (edict_t *self);
void SP_misc_strogg_ship (edict_t *self);
void SP_misc_teleporter (edict_t *self);
void SP_misc_teleporter_dest (edict_t *self);
void SP_misc_blackhole (edict_t *self);
void SP_misc_eastertank (edict_t *self);
void SP_misc_easterchick (edict_t *self);
void SP_misc_easterchick2 (edict_t *self);

void SP_monster_berserk (edict_t *self);
void SP_monster_gladiator (edict_t *self);
void SP_monster_gunner (edict_t *self);
void SP_monster_infantry (edict_t *self);
void SP_monster_soldier_light (edict_t *self);
void SP_monster_soldier (edict_t *self);
void SP_monster_soldier_ss (edict_t *self);
void SP_monster_tank (edict_t *self);
void SP_monster_medic (edict_t *self);
void SP_monster_flipper (edict_t *self);
void SP_monster_chick (edict_t *self);
void SP_monster_parasite (edict_t *self);
void SP_monster_flyer (edict_t *self);
void SP_monster_brain (edict_t *self);
void SP_monster_floater (edict_t *self);
void SP_monster_hover (edict_t *self);
void SP_monster_mutant (edict_t *self);
void SP_monster_supertank (edict_t *self);
void SP_monster_boss2 (edict_t *self);
void SP_monster_jorg (edict_t *self);
void SP_monster_boss3_stand (edict_t *self);

void SP_monster_commander_body (edict_t *self);

void SP_turret_breach (edict_t *self);
void SP_turret_base (edict_t *self);
void SP_turret_driver (edict_t *self);

// RAFAEL 14-APR-98
void SP_monster_soldier_hypergun (edict_t *self);
void SP_monster_soldier_lasergun (edict_t *self);
void SP_monster_soldier_ripper (edict_t *self);
void SP_monster_fixbot (edict_t *self);
void SP_monster_gekk (edict_t *self);
void SP_monster_chick_heat (edict_t *self);
void SP_monster_gladb (edict_t *self);
void SP_monster_boss5 (edict_t *self);
void SP_rotating_light (edict_t *self);
void SP_object_repair (edict_t *self);
// void SP_misc_crashviper (edict_t *ent);
void SP_misc_viper_missile (edict_t *self);
// void SP_misc_amb4 (edict_t *ent);
void SP_target_mal_laser (edict_t *ent);
void SP_misc_transport (edict_t *ent);
// END 14-APR-98

// void SP_misc_nuke (edict_t *ent);

void SP_target_steam (edict_t *self);
void SP_func_plat2 (edict_t *ent);


spawn_t	spawns[] = {
	{"item_health", SP_item_health},
	{"item_health_small", SP_item_health_small},
	{"item_health_large", SP_item_health_large},
	{"item_health_mega", SP_item_health_mega},

	{"info_player_start", SP_info_player_start},
	{"info_player_deathmatch", SP_info_player_deathmatch},
	{"info_player_coop", SP_info_player_coop},
	{"info_player_intermission", SP_info_player_intermission},
//ZOID
	{"info_player_team1", SP_info_player_team1},
	{"info_player_team2", SP_info_player_team2},
//ZOID

	{"func_plat", SP_func_plat},
	{"func_button", SP_func_button},
	{"func_door", SP_func_door},
	{"func_door_secret", SP_func_door_secret},
	{"func_door_rotating", SP_func_door_rotating},
	{"func_rotating", SP_func_rotating},
	{"func_train", SP_func_train},
	{"func_water", SP_func_water},
	{"func_conveyor", SP_func_conveyor},
	{"func_areaportal", SP_func_areaportal},
	{"func_clock", SP_func_clock},
	{"func_wall", SP_func_wall},
	{"func_object", SP_func_object},
	{"func_timer", SP_func_timer},
	{"func_explosive", SP_func_explosive},
	{"func_killbox", SP_func_killbox},

	// RAFAEL
	{"func_object_repair", SP_object_repair},
	{"rotating_light", SP_rotating_light},

	{"trigger_always", SP_trigger_always},
	{"trigger_once", SP_trigger_once},
	{"trigger_multiple", SP_trigger_multiple},
	{"trigger_relay", SP_trigger_relay},
	{"trigger_push", SP_trigger_push},
	{"trigger_hurt", SP_trigger_hurt},
	{"trigger_key", SP_trigger_key},
	{"trigger_counter", SP_trigger_counter},
	{"trigger_elevator", SP_trigger_elevator},
	{"trigger_gravity", SP_trigger_gravity},
	{"trigger_monsterjump", SP_trigger_monsterjump},

	{"target_temp_entity", SP_target_temp_entity},
	{"target_speaker", SP_target_speaker},
	{"target_explosion", SP_target_explosion},
	{"target_changelevel", SP_target_changelevel},
	{"target_secret", SP_target_secret},
	{"target_goal", SP_target_goal},
	{"target_splash", SP_target_splash},
	{"target_spawner", SP_target_spawner},
	{"target_blaster", SP_target_blaster},
	{"target_crosslevel_trigger", SP_target_crosslevel_trigger},
	{"target_crosslevel_target", SP_target_crosslevel_target},
	{"target_laser", SP_target_laser},
	{"target_help", SP_target_help},
	{"target_lightramp", SP_target_lightramp},
	{"target_earthquake", SP_target_earthquake},
	{"target_character", SP_target_character},
	{"target_string", SP_target_string},

	// RAFAEL 15-APR-98
	{"target_mal_laser", SP_target_mal_laser},

	{"worldspawn", SP_worldspawn},
	{"viewthing", SP_viewthing},

	{"light", SP_light},
	{"light_mine1", SP_light_mine1},
	{"light_mine2", SP_light_mine2},
	{"info_null", SP_info_null},
	{"func_group", SP_info_null},
	{"info_notnull", SP_info_notnull},
	{"path_corner", SP_path_corner},
	{"point_combat", SP_point_combat},

	{"misc_explobox", SP_misc_explobox},
	{"misc_banner", SP_misc_banner},
//ZOID
	{"misc_ctf_banner", SP_misc_ctf_banner},
	{"misc_ctf_small_banner", SP_misc_ctf_small_banner},
//ZOID
	{"misc_satellite_dish", SP_misc_satellite_dish},
#if 0 // remove monster code
	{"misc_actor", SP_misc_actor},
#endif
	{"misc_gib_arm", SP_misc_gib_arm},
	{"misc_gib_leg", SP_misc_gib_leg},
	{"misc_gib_head", SP_misc_gib_head},
#if 0 // remove monster code
	{"misc_insane", SP_misc_insane},
#endif
	{"misc_deadsoldier", SP_misc_deadsoldier},
	{"misc_viper", SP_misc_viper},
	{"misc_viper_bomb", SP_misc_viper_bomb},
	{"misc_bigviper", SP_misc_bigviper},
	{"misc_strogg_ship", SP_misc_strogg_ship},
	{"misc_teleporter", SP_misc_teleporter},
	{"misc_teleporter_dest", SP_misc_teleporter_dest},
//ZOID
	{"trigger_teleport", SP_trigger_teleport},
	{"info_teleport_destination", SP_info_teleport_destination},
//ZOID
	{"misc_blackhole", SP_misc_blackhole},
	{"misc_eastertank", SP_misc_eastertank},
	{"misc_easterchick", SP_misc_easterchick},
	{"misc_easterchick2", SP_misc_easterchick2},

	// RAFAEL
//	{"misc_crashviper", SP_misc_crashviper},
//	{"misc_viper_missile", SP_misc_viper_missile},
//	{"misc_amb4", SP_misc_amb4},
	// RAFAEL 17-APR-98
	{"misc_transport", SP_misc_transport},
	// END 17-APR-98
	// RAFAEL 12-MAY-98
//	{"misc_nuke", SP_misc_nuke},

#if 0 // remove monster code
	{"monster_berserk", SP_monster_berserk},
	{"monster_gladiator", SP_monster_gladiator},
	{"monster_gunner", SP_monster_gunner},
	{"monster_infantry", SP_monster_infantry},
	{"monster_soldier_light", SP_monster_soldier_light},
	{"monster_soldier", SP_monster_soldier},
	{"monster_soldier_ss", SP_monster_soldier_ss},
	{"monster_tank", SP_monster_tank},
	{"monster_tank_commander", SP_monster_tank},
	{"monster_medic", SP_monster_medic},
	{"monster_flipper", SP_monster_flipper},
	{"monster_chick", SP_monster_chick},
	{"monster_parasite", SP_monster_parasite},
	{"monster_flyer", SP_monster_flyer},
	{"monster_brain", SP_monster_brain},
	{"monster_floater", SP_monster_floater},
	{"monster_hover", SP_monster_hover},
	{"monster_mutant", SP_monster_mutant},
	{"monster_supertank", SP_monster_supertank},
	{"monster_boss2", SP_monster_boss2},
	{"monster_boss3_stand", SP_monster_boss3_stand},
	{"monster_jorg", SP_monster_jorg},

	{"monster_commander_body", SP_monster_commander_body},

	// RAFAEL 14-APR-98
	{"monster_soldier_hypergun", SP_monster_soldier_hypergun},
	{"monster_soldier_lasergun", SP_monster_soldier_lasergun},
	{"monster_soldier_ripper",	SP_monster_soldier_ripper},
	{"monster_fixbot", SP_monster_fixbot},
	{"monster_gekk", SP_monster_gekk},
	{"monster_chick_heat", SP_monster_chick_heat},
	{"monster_gladb", SP_monster_gladb},
	{"monster_boss5", SP_monster_boss5},
	// END 14-APR-98

	{"turret_breach", SP_turret_breach},
	{"turret_base", SP_turret_base},
	{"turret_driver", SP_turret_driver},
#endif
	{"target_steam", SP_target_steam},
	{"func_plat2", SP_func_plat2},

	{NULL, NULL}
};

/*
===============
ED_CallSpawn

Finds the spawn function for the entity and calls it
===============
*/
void ED_CallSpawn (edict_t *ent)
{
	spawn_t	*s;
	gitem_t	*item;
	int		i;

	if (!ent->classname)
	{
		gi.dprintf ("ED_CallSpawn: NULL classname\n");
		return;
	}
	//ScarFace
	if (!strcmp(ent->classname, "weapon_nailgun"))
		ent->classname = "weapon_etf_rifle";
	if (!strcmp(ent->classname, "ammo_nails"))
		ent->classname = "ammo_flechettes";
	if (!strcmp(ent->classname, "weapon_heatbeam"))
		ent->classname = "weapon_plasmabeam";

	// check item spawn functions
	for (i=0,item=itemlist ; i<game.num_items ; i++,item++)
	{
		if (!item->classname)
			continue;
		if (!strcmp(item->classname, ent->classname))
		{	// found it
			SpawnItem (ent, item);
			return;
		}
	}

	// check normal spawn functions
	for (s=spawns ; s->name ; s++)
	{
		if (!strcmp(s->name, ent->classname))
		{	// found it
			s->spawn (ent);
			return;
		}
	}
/*
	if (!((ent->classname[0] == 'm') && 
		  (ent->classname[1] == 'o') && 
		  (ent->classname[2] != 'n')))
	{
		gi.dprintf ("%s doesn't have a spawn function\n", ent->classname);
	}
*/
}

/*
=============
ED_NewString
=============
*/
char *ED_NewString (char *string)
{
	char	*newb, *new_p;
	int		i,l;
	
	l = strlen(string) + 1;

	newb = gi.TagMalloc (l, TAG_LEVEL);

	new_p = newb;

	for (i=0 ; i< l ; i++)
	{
		if (string[i] == '\\' && i < l-1)
		{
			i++;
			if (string[i] == 'n')
				*new_p++ = '\n';
			else
				*new_p++ = '\\';
		}
		else
			*new_p++ = string[i];
	}
	
	return newb;
}




/*
===============
ED_ParseField

Takes a key/value pair and sets the binary values
in an edict
===============
*/
void ED_ParseField (char *key, char *value, edict_t *ent)
{
	field_t	*f;
	byte	*b;
	float	v;
	vec3_t	vec;

	for (f=fields ; f->name ; f++)
	{
		if (!Q_stricmp(f->name, key))
		{	// found it
			if (f->flags & FFL_SPAWNTEMP)
				b = (byte *)&st;
			else
				b = (byte *)ent;

			switch (f->type)
			{
			case F_LSTRING:
				*(char **)(b+f->ofs) = ED_NewString (value);
				break;
			case F_VECTOR:
				sscanf (value, "%f %f %f", &vec[0], &vec[1], &vec[2]);
				((float *)(b+f->ofs))[0] = vec[0];
				((float *)(b+f->ofs))[1] = vec[1];
				((float *)(b+f->ofs))[2] = vec[2];
				break;
			case F_INT:
				*(int *)(b+f->ofs) = atoi(value);
				break;
			case F_FLOAT:
				*(float *)(b+f->ofs) = atof(value);
				break;
			case F_ANGLEHACK:
				v = atof(value);
				((float *)(b+f->ofs))[0] = 0;
				((float *)(b+f->ofs))[1] = v;
				((float *)(b+f->ofs))[2] = 0;
				break;
			case F_IGNORE:
				break;
			}
			return;
		}
	}
	gi.dprintf ("%s is not a field\n", key);
}

/*
====================
ED_ParseEdict

Parses an edict out of the given string, returning the new position
ed should be a properly initialized empty edict.
====================
*/
char *ED_ParseEdict (char *data, edict_t *ent)
{
	qboolean	init;
	char		keyname[256];
	char		*com_token;

	init = false;
	memset (&st, 0, sizeof(st));

// go through all the dictionary pairs
	while (1)
	{	
	// parse key
		com_token = COM_Parse (&data);
		if (com_token[0] == '}')
			break;
		if (!data)
			gi.error ("ED_ParseEntity: EOF without closing brace");

		strncpy (keyname, com_token, sizeof(keyname)-1);
		
	// parse value	
		com_token = COM_Parse (&data);
		if (!data)
			gi.error ("ED_ParseEntity: EOF without closing brace");

		if (com_token[0] == '}')
			gi.error ("ED_ParseEntity: closing brace without data");

		init = true;	

	// keynames with a leading underscore are used for utility comments,
	// and are immediately discarded by quake
		if (keyname[0] == '_')
			continue;

		ED_ParseField (keyname, com_token, ent);
	}

	if (!init)
		memset (ent, 0, sizeof(*ent));

	return data;
}


/*
================
G_FindTeams

Chain together all entities with a matching team field.

All but the first will have the FL_TEAMSLAVE flag set.
All but the last will have the teamchain field set to the next one
================
*/
void G_FindTeams (void)
{
	edict_t	*e, *e2, *chain;
	int		i, j;
	int		c, c2;

	c = 0;
	c2 = 0;
	for (i=1, e=g_edicts+i ; i < globals.num_edicts ; i++,e++)
	{
		if (!e->inuse)
			continue;
		if (!e->team)
			continue;
		if (e->flags & FL_TEAMSLAVE)
			continue;
		chain = e;
		e->teammaster = e;
		c++;
		c2++;
		for (j=i+1, e2=e+1 ; j < globals.num_edicts ; j++,e2++)
		{
			if (!e2->inuse)
				continue;
			if (!e2->team)
				continue;
			if (e2->flags & FL_TEAMSLAVE)
				continue;
			if (!strcmp(e->team, e2->team))
			{
				c2++;
				chain->teamchain = e2;
				e2->teammaster = e;
				chain = e2;
				e2->flags |= FL_TEAMSLAVE;
			}
		}
	}

	gi.dprintf ("%i teams with %i entities\n", c, c2);
}

void CheckNodeCalculation(edict_t	*ent)
{
	if (nodes_done || (trail_head >= 500))	// assume it's done if > 500 nodes
	{
//		if (bot_calc_nodes->value)
//		{
			gi.cvar_set("bot_calc_nodes", "0");
			gi.dprintf("\nDynamic node-table generation DISABLED\n\n");
//		}
	}
	else
	{
//		if (!bot_calc_nodes->value)
//		{
			gi.cvar_set("bot_calc_nodes", "1");
			gi.dprintf("\nDynamic node-table generation ENABLED\n\n");
//		}
	}

	G_FreeEdict(ent);
}

/*
==============
SpawnEntities

Creates a server's entity / program execution context by
parsing textual entity definitions out of an ent file.
==============
*/
void SpawnEntities (char *mapname, char *entities, char *spawnpoint)
{
	edict_t		*ent;
	int			inhibit;
	char		*com_token;
	int			i;
	float		skill_level;

	skill_level = floor (skill->value);
	if (skill_level < 0)
		skill_level = 0;
	if (skill_level > 3)
		skill_level = 3;
	if (skill->value != skill_level)
		gi.cvar_forceset("skill", va("%f", skill_level));

	SaveClientData ();

	gi.FreeTags (TAG_LEVEL);

	memset (&level, 0, sizeof(level));
	memset (g_edicts, 0, game.maxentities * sizeof (g_edicts[0]));

	strncpy (level.mapname, mapname, sizeof(level.mapname)-1);
	strncpy (game.spawnpoint, spawnpoint, sizeof(game.spawnpoint)-1);

	// set client fields on player ents
	for (i=0 ; i<game.maxclients ; i++)
		g_edicts[i+1].client = game.clients + i;

	ent = NULL;
	inhibit = 0;

// parse ents
	while (1)
	{
		// parse the opening brace	
		com_token = COM_Parse (&entities);
		if (!entities)
			break;
		if (com_token[0] != '{')
			gi.error ("ED_LoadFromFile: found %s when expecting {",com_token);

		if (!ent)
			ent = g_edicts;
		else
			ent = G_Spawn ();
		entities = ED_ParseEdict (entities, ent);
		
		// yet another map hack
		if (!stricmp(level.mapname, "command") && !stricmp(ent->classname, "trigger_once") && !stricmp(ent->model, "*27"))
			ent->spawnflags &= ~SPAWNFLAG_NOT_HARD;

		// ROGUE
		//ahh, the joys of map hacks .. 
		if (!Q_stricmp(level.mapname, "rhangar2") && !Q_stricmp(ent->classname, "func_door_rotating") && ent->targetname && !Q_stricmp(ent->targetname, "t265"))
			ent->spawnflags &= ~SPAWNFLAG_NOT_COOP;
		if (!Q_stricmp(level.mapname, "rhangar2") && !Q_stricmp(ent->classname, "trigger_always") && ent->target && !Q_stricmp(ent->target, "t265"))
			ent->spawnflags |= SPAWNFLAG_NOT_COOP;
		if (!Q_stricmp(level.mapname, "rhangar2") && !Q_stricmp(ent->classname, "func_wall") && !Q_stricmp(ent->model, "*15"))
			ent->spawnflags |= SPAWNFLAG_NOT_COOP;
		// rogue

		// remove things (except the world) from different skill levels or deathmatch
		if (ent != g_edicts)
		{
			if (deathmatch->value)
			{
				if ( ent->spawnflags & SPAWNFLAG_NOT_DEATHMATCH )
				{
					G_FreeEdict (ent);	
					inhibit++;
					continue;
				}
			}
			else
			{
				if ( /* ((coop->value) && (ent->spawnflags & SPAWNFLAG_NOT_COOP)) || */
					((skill->value == 0) && (ent->spawnflags & SPAWNFLAG_NOT_EASY)) ||
					((skill->value == 1) && (ent->spawnflags & SPAWNFLAG_NOT_MEDIUM)) ||
					(((skill->value == 2) || (skill->value == 3)) && (ent->spawnflags & SPAWNFLAG_NOT_HARD))
					)
					{
						G_FreeEdict (ent);	
						inhibit++;
						continue;
					}
			}

			ent->spawnflags &= ~(SPAWNFLAG_NOT_EASY|SPAWNFLAG_NOT_MEDIUM|SPAWNFLAG_NOT_HARD|SPAWNFLAG_NOT_COOP|SPAWNFLAG_NOT_DEATHMATCH);
		}

//PGM - do this before calling the spawn function so it can be overridden.
#ifdef ROGUE_GRAVITY
		ent->gravityVector[0] =  0.0;
		ent->gravityVector[1] =  0.0;
		ent->gravityVector[2] = -1.0;
#endif
//PGM

		ED_CallSpawn (ent);

		ent->s.renderfx |= RF_IR_VISIBLE;		//PGM
	}	

	// we might read in a CTF flag
	PlayerTrail_Init ();

	gi.dprintf ("%i entities inhibited\n", inhibit);

#ifdef DEBUG
	i = 1;
	ent = EDICT_NUM(i);
	while (i < globals.num_edicts) {
		if (ent->inuse != 0 || ent->inuse != 1)
			Com_DPrintf("Invalid entity %d\n", i);
		i++, ent++;
	}
#endif

	G_FindTeams ();

	if (!G_Find(NULL, FOFS(classname), "item_flag_team1"))
	{	// not a CTF level
		gi.cvar_forceset("ctf", "0");
	}
	else	// make sure CTF is enabled, since there is a flag
	{
		gi.cvar_forceset("ctf", "1");
//		gi.cvar_forceset("grapple", "1");
/*
		if (ctf->value) {
			gi.configstring (CS_STATUSBAR, ctf_statusbar);
			//precaches
			gi.imageindex("sbctf1");
			gi.imageindex("sbctf2");
			gi.imageindex("i_ctf1");
			gi.imageindex("i_ctf2");
			gi.imageindex("i_ctf1d");
			gi.imageindex("i_ctf2d");
			gi.imageindex("i_ctf1t");
			gi.imageindex("i_ctf2t");
			gi.imageindex("i_ctfj");
		}
*/	
// AJ detect TTCTF
	if (!G_Find(NULL, FOFS(classname), "item_flag_team3"))
		gi.cvar_forceset("ttctf", "0");
	else gi.cvar_forceset("ttctf", "1");
// end AJ
	}
// AJ TEMP CHANGE
//	aj_choosebar(); 
// end AJ
//ZOID
	CTFSetupTechSpawn();
//ZOID

	// spawn an entity, that will decide whether or not to disable node calculation
	ent = G_Spawn();
	ent->think = CheckNodeCalculation;
	ent->nextthink = level.time + 1.5;	// give the items time to set their reachable nodes

	check_nodes_done = NULL;
}


//===================================================================

#if 0
	// cursor positioning
	xl <value>
	xr <value>
	yb <value>
	yt <value>
	xv <value>
	yv <value>

	// drawing
	statpic <name>
	pic <stat>
	num <fieldwidth> <stat>
	string <stat>

	// control
	if <stat>
	ifeq <stat> <value>
	ifbit <stat> <value>
	endif

#endif

char *single_statusbar = 
"yb	-24 "

// health
"xv	0 "
"hnum "
"xv	50 "
"pic 0 "

// ammo
"if 2 "
"	xv	100 "
"	anum "
"	xv	150 "
"	pic 2 "
"endif "

// armor
"if 4 "
"	xv	200 "
"	rnum "
"	xv	250 "
"	pic 4 "
"endif "

// selected item
"if 6 "
"	xv	296 "
"	pic 6 "
"endif "

"yb	-50 "

// picked up item
"if 7 "
"	xv	0 "
"	pic 7 "
"	xv	26 "
"	yb	-42 "
"	stat_string 8 "
"	yb	-50 "
"endif "

// timer
"if 9 "
"	xv	262 "
"	num	2	10 "
"	xv	296 "
"	pic	9 "
"endif "

//  help / weapon icon 
"if 11 "
"	xv	148 "
"	pic	11 "
"endif "
;

char *dm_statusbar =
"yb	-24 "

// health
"xv	0 "
"hnum "
"xv	50 "
"pic 0 "

// ammo
"if 2 "
"	xv	100 "
"	anum "
"	xv	150 "
"	pic 2 "
"endif "

// armor
"if 4 "
"	xv	200 "
"	rnum "
"	xv	250 "
"	pic 4 "
"endif "

// selected item
"if 6 "
"	xv	296 "
"	pic 6 "
"endif "

"yb	-50 "

// picked up item
"if 7 "
"	xv	0 "
"	pic 7 "
"	xv	26 "
"	yb	-42 "
"	stat_string 8 "
"	yb	-50 "
"endif "

// timer
"if 9 "
"	xv	246 "
"	num	2	10 "
"	xv	296 "
"	pic	9 "
"endif "

//  help / weapon icon 
"if 11 "
"	xv	148 "
"	pic	11 "
"endif "

//  frags
"xr	-50 "
"yt 2 "
"num 3 14"
;

extern qboolean	respawn_flag;
extern int num_dm_spots;

/*QUAKED worldspawn (0 0 0) ?

Only used for the world.
"sky"	environment map name
"skyaxis"	vector axis for rotating sky
"skyrotate"	speed of rotation in degrees/second
"sounds"	music cd track number
"gravity"	800 is default gravity
"message"	text to print at user logon
*/
void SP_worldspawn (edict_t *ent)
{
	ent->movetype = MOVETYPE_PUSH;
	ent->solid = SOLID_BSP;
	ent->inuse = true;			// since the world doesn't use G_Spawn()
	ent->s.modelindex = 1;		// world model is always index 1

	//---------------

	num_players = 0;
	bot_count = 0;
	bot_frametime = 0.1;	// set if using distributed thinking
	botdebug = 0;
	spawn_bots = 0;
	num_dm_spots = 0;
	paused = false;

	weapons_head = health_head = bonus_head = ammo_head = NULL;

	// reserve some spots for dead player bodies
	InitBodyQue ();

	// set configstrings for items
	SetItemNames ();

	if (st.nextmap)
		strcpy (level.nextmap, st.nextmap);

	// make some data visible to the server

	if (ent->message && ent->message[0])
	{
		gi.configstring (CS_NAME, ent->message);
		strncpy (level.level_name, ent->message, sizeof(level.level_name));
	}
	else
		strncpy (level.level_name, level.mapname, sizeof(level.level_name));

	if (st.sky && st.sky[0])
		gi.configstring (CS_SKY, st.sky);
	else
		gi.configstring (CS_SKY, "unit1_");

	gi.configstring (CS_SKYROTATE, va("%f", st.skyrotate) );

	gi.configstring (CS_SKYAXIS, va("%f %f %f",
		st.skyaxis[0], st.skyaxis[1], st.skyaxis[2]) );

	gi.configstring (CS_CDTRACK, va("%i", ent->sounds) );

	gi.configstring (CS_MAXCLIENTS, va("%i", (int)(maxclients->value) ) );

	//---------------

	// set ammo item lookups
	item_shells = FindItem("shells");
	item_cells = FindItem("cells");
	item_bullets = FindItem("bullets");
	item_rockets = FindItem("rockets");
	item_slugs = FindItem("slugs");
	item_grenades = FindItem("grenades");

	item_blaster	= FindItem("blaster");
	item_shotgun	= FindItem("shotgun");
	item_supershotgun	= FindItem("super shotgun");
	item_machinegun	= FindItem("machinegun");
	item_chaingun	= FindItem("chaingun");
	item_grenadelauncher	= FindItem("grenade launcher");
	item_rocketlauncher	= FindItem("rocket launcher");
	item_railgun	= FindItem("railgun");
	item_hyperblaster	= FindItem("hyperblaster");
	item_bfg10k	= FindItem("bfg10k");

// AJ
	item_phalanx	= FindItem("Phalanx");
	item_ionripper	= FindItem("Ionripper");
	item_trap	= FindItem("Trap");
	item_quadfire	= FindItem("DualFire Damage");
	item_ir_goggles = FindItem("IR Goggles");
	item_double = FindItem("Double Damage");
	item_sphere_vengeance = FindItem("Vengeance sphere");
	item_sphere_hunter = FindItem("Hunter sphere");
	item_sphere_defender = FindItem("Defender sphere");
	item_doppleganger = FindItem("Doppleganger");

	item_magslugs	= FindItem("Mag Slug");

	item_chainfist	= FindItem("Chainfist");
	item_shockwave	= FindItem("Shockwave");
	item_disruptor	= FindItem("Disruptor");
	item_etfrifle	= FindItem("ETF Rifle");
	item_plasmabeam	= FindItem("Plasma Beam");
	item_proxlauncher	= FindItem("Prox Launcher");
	item_prox = FindItem("Prox");
	item_tesla = FindItem("Tesla");
	item_rounds	= FindItem("Rounds");
	item_flechettes	= FindItem("Flechettes");
	
	lithium_init();

	// status bar program (moved below FindItem() above by AJ)
	// code removed by AJ (moved to g_lithium.c)
// end AJ

	if (!respawn_flag)		// only read in bots once, or team links for players will become corrupted
	{
		// read data from bots.cfg
		ReadBotConfig();
	}
	else if (teamplay->value)	// clear the scores
	{
		int i;

		for (i=0; i<MAX_TEAMS; i++)
		{
			if (!bot_teams[i])
				break;

			bot_teams[i]->score = 0;
			bot_teams[i]->last_grouping = 0;
		}
	}

	// help icon for statusbar
	gi.imageindex ("i_help");
	level.pic_health = gi.imageindex ("i_health");
	gi.imageindex ("help");
	gi.imageindex ("field_3");

	if (!st.gravity)
		gi.cvar_set("sv_gravity", "800");
	else
		gi.cvar_set("sv_gravity", st.gravity);

	snd_fry = gi.soundindex ("player/fry.wav");	// standing in lava / slime

	PrecacheItem (FindItem ("Blaster"));

	gi.soundindex ("player/lava1.wav");
	gi.soundindex ("player/lava2.wav");

	gi.soundindex ("misc/pc_up.wav");
	gi.soundindex ("misc/talk1.wav");

	gi.soundindex ("misc/udeath.wav");

	// gibs
	gi.soundindex ("items/respawn1.wav");

	// sexed sounds
	// sexed sounds
	gi.soundindex ("*death1.wav");
	gi.soundindex ("*death2.wav");
	gi.soundindex ("*death3.wav");
	gi.soundindex ("*death4.wav");
	gi.soundindex ("*fall1.wav");
	gi.soundindex ("*fall2.wav");	
	gi.soundindex ("*gurp1.wav");		// drowning damage
	gi.soundindex ("*gurp2.wav");	
	gi.soundindex ("*jump1.wav");		// player jump
	gi.soundindex ("*pain25_1.wav");
	gi.soundindex ("*pain25_2.wav");
	gi.soundindex ("*pain50_1.wav");
	gi.soundindex ("*pain50_2.wav");
	gi.soundindex ("*pain75_1.wav");
	gi.soundindex ("*pain75_2.wav");
	gi.soundindex ("*pain100_1.wav");
	gi.soundindex ("*pain100_2.wav");

	//-------------------

	gi.soundindex ("player/female/death1.wav");
	gi.soundindex ("player/female/death2.wav");
	gi.soundindex ("player/female/death3.wav");
	gi.soundindex ("player/female/death4.wav");

	gi.soundindex ("player/female/fall1.wav");
	gi.soundindex ("player/female/fall2.wav");	

	gi.soundindex ("player/female/gurp1.wav");		// drowning damage
	gi.soundindex ("player/female/gurp2.wav");	

	gi.soundindex ("player/female/jump1.wav");		// player jump

	gi.soundindex ("player/female/pain25_1.wav");
	gi.soundindex ("player/female/pain25_2.wav");
	gi.soundindex ("player/female/pain50_1.wav");
	gi.soundindex ("player/female/pain50_2.wav");
	gi.soundindex ("player/female/pain75_1.wav");
	gi.soundindex ("player/female/pain75_2.wav");
	gi.soundindex ("player/female/pain100_1.wav");
	gi.soundindex ("player/female/pain100_2.wav");

	//-------------------

	gi.soundindex ("player/gasp1.wav");		// gasping for air
	gi.soundindex ("player/gasp2.wav");		// head breaking surface, not gasping

	gi.soundindex ("player/watr_in.wav");	// feet hitting water
	gi.soundindex ("player/watr_out.wav");	// feet leaving water

	gi.soundindex ("player/watr_un.wav");	// head going underwater
	
	gi.soundindex ("player/u_breath1.wav");
	gi.soundindex ("player/u_breath2.wav");

	gi.soundindex ("items/pkup.wav");		// bonus item pickup
	gi.soundindex ("world/land.wav");		// landing thud
	gi.soundindex ("misc/h2ohit1.wav");		// landing splash

	gi.soundindex ("items/damage.wav");
	// ROGUE - double damage
	gi.soundindex ("misc/ddamage1.wav");
	// rogue
	gi.soundindex ("items/protect.wav");
	gi.soundindex ("items/protect4.wav");
	gi.soundindex ("weapons/noammo.wav");

	gi.soundindex ("infantry/inflies1.wav");

	sm_meat_index = gi.modelindex ("models/objects/gibs/sm_meat/tris.md2");
	gi.modelindex ("models/objects/gibs/arm/tris.md2");
	gi.modelindex ("models/objects/gibs/bone/tris.md2");
	gi.modelindex ("models/objects/gibs/bone2/tris.md2");
	gi.modelindex ("models/objects/gibs/chest/tris.md2");
	gi.modelindex ("models/objects/gibs/skull/tris.md2");
	gi.modelindex ("models/objects/gibs/head2/tris.md2");

		// precache all supported view_weapon models
// AJ patched for 317 vwep
#ifdef USE_ID_VWEP

	// sexed models
	// THIS ORDER MUST MATCH THE DEFINES IN g_local.h
	// you can add more, max 19 (pete change)
	// these models are only loaded in coop or deathmatch. not singleplayer.
	if (coop->value || deathmatch->value)
	{
		gi.modelindex ("#w_blaster.md2");
		gi.modelindex ("#w_shotgun.md2");
		gi.modelindex ("#w_sshotgun.md2");
		gi.modelindex ("#w_machinegun.md2");
		gi.modelindex ("#w_chaingun.md2");
		gi.modelindex ("#a_grenades.md2");
		gi.modelindex ("#w_glauncher.md2");
		gi.modelindex ("#w_rlauncher.md2");
		gi.modelindex ("#w_hyperblaster.md2");
		gi.modelindex ("#w_railgun.md2");
		gi.modelindex ("#w_bfg.md2");

		gi.modelindex ("#w_phalanx.md2");
		gi.modelindex ("#w_ripper.md2");
	}
#else
// AJ: added use_vwep clause
	if (view_weapons->value || use_vwep->value)
	{
		int i;
		for (i=0; i<num_view_weapons; i++)
		{
			char	str[128];

			sprintf( str, "players/%s/a_grenades.md2", view_weapon_models[i] );
			gi.modelindex ( str );
			sprintf( str, "players/%s/w_bfg.md2", view_weapon_models[i] );
			gi.modelindex ( str );
			sprintf( str, "players/%s/w_blaster.md2", view_weapon_models[i] );
			gi.modelindex ( str );
			sprintf( str, "players/%s/w_chaingun.md2", view_weapon_models[i] );
			gi.modelindex ( str );
			sprintf( str, "players/%s/w_glauncher.md2", view_weapon_models[i] );
			gi.modelindex ( str );
			sprintf( str, "players/%s/w_grapple.md2", view_weapon_models[i] );
			gi.modelindex ( str );
			sprintf( str, "players/%s/w_hyperblaster.md2", view_weapon_models[i] );
			gi.modelindex ( str );
			sprintf( str, "players/%s/w_machinegun.md2", view_weapon_models[i] );
			gi.modelindex ( str );
			sprintf( str, "players/%s/w_railgun.md2", view_weapon_models[i] );
			gi.modelindex ( str );
			sprintf( str, "players/%s/w_rlauncher.md2", view_weapon_models[i] );
			gi.modelindex ( str );
			sprintf( str, "players/%s/w_shotgun.md2", view_weapon_models[i] );
			gi.modelindex ( str );
			sprintf( str, "players/%s/w_sshotgun.md2", view_weapon_models[i] );
			gi.modelindex ( str );

		}
	}
#endif

//
// Setup light animation tables. 'a' is total darkness, 'z' is doublebright.
//

	// 0 normal
	gi.configstring(CS_LIGHTS+0, "m");
	
	// 1 FLICKER (first variety)
	gi.configstring(CS_LIGHTS+1, "mmnmmommommnonmmonqnmmo");
	
	// 2 SLOW STRONG PULSE
	gi.configstring(CS_LIGHTS+2, "abcdefghijklmnopqrstuvwxyzyxwvutsrqponmlkjihgfedcba");
	
	// 3 CANDLE (first variety)
	gi.configstring(CS_LIGHTS+3, "mmmmmaaaaammmmmaaaaaabcdefgabcdefg");
	
	// 4 FAST STROBE
	gi.configstring(CS_LIGHTS+4, "mamamamamama");
	
	// 5 GENTLE PULSE 1
	gi.configstring(CS_LIGHTS+5,"jklmnopqrstuvwxyzyxwvutsrqponmlkj");
	
	// 6 FLICKER (second variety)
	gi.configstring(CS_LIGHTS+6, "nmonqnmomnmomomno");
	
	// 7 CANDLE (second variety)
	gi.configstring(CS_LIGHTS+7, "mmmaaaabcdefgmmmmaaaammmaamm");
	
	// 8 CANDLE (third variety)
	gi.configstring(CS_LIGHTS+8, "mmmaaammmaaammmabcdefaaaammmmabcdefmmmaaaa");
	
	// 9 SLOW STROBE (fourth variety)
	gi.configstring(CS_LIGHTS+9, "aaaaaaaazzzzzzzz");
	
	// 10 FLUORESCENT FLICKER
	gi.configstring(CS_LIGHTS+10, "mmamammmmammamamaaamammma");

	// 11 SLOW PULSE NOT FADE TO BLACK
	gi.configstring(CS_LIGHTS+11, "abcdefghijklmnopqrrqponmlkjihgfedcba");
	
	// styles 32-62 are assigned by the light program for switchable lights

	// 63 testing
	gi.configstring(CS_LIGHTS+63, "a");

}

//
// ROGUE
//

// FindSpawnPoint
// PMM - this is used by the medic commander (possibly by the carrier) to find a good spawn point
// if the startpoint is bad, try above the startpoint for a bit

qboolean FindSpawnPoint (vec3_t startpoint, vec3_t mins, vec3_t maxs, vec3_t spawnpoint, float maxMoveUp)
{
	trace_t		tr;
	float		height;
	vec3_t		top;

	height = maxs[2] - mins[2];

	tr = gi.trace (startpoint, mins, maxs, startpoint, NULL, MASK_MONSTERSOLID|CONTENTS_PLAYERCLIP);
	if((tr.startsolid || tr.allsolid) || (tr.ent != world))
	{
//		if ( ((tr.ent->svflags & SVF_MONSTER) && (tr.ent->health <= 0)) ||
//			 (tr.ent->svflags & SVF_DAMAGEABLE) )
//		{
//			T_Damage (tr.ent, self, self, vec3_origin, self->enemy->s.origin,
//						pain_normal, hurt, 0, 0, MOD_UNKNOWN);

		VectorCopy (startpoint, top);
		top[2] += maxMoveUp;
/*
		gi.WriteByte (svc_temp_entity);
		gi.WriteByte (TE_DEBUGTRAIL);
		gi.WritePosition (top);
		gi.WritePosition (startpoint);
		gi.multicast (startpoint, MULTICAST_ALL);	
*/
		tr = gi.trace (top, mins, maxs, startpoint, NULL, MASK_MONSTERSOLID);
		if (tr.startsolid || tr.allsolid)
		{
//			if ((g_showlogic) && (g_showlogic->value))
//				if (tr.ent)
//					gi.dprintf("FindSpawnPoint: failed to find a point -- blocked by %s\n", tr.ent->classname);
//				else
//					gi.dprintf("FindSpawnPoint: failed to find a point\n");

			return false;
		} 
		else
		{
//			if ((g_showlogic) && (g_showlogic->value))
//				gi.dprintf ("FindSpawnPoint: %s -> %s\n", vtos (startpoint), vtos (tr.endpos));
			VectorCopy (tr.endpos, spawnpoint);
			return true;
		}
	}
	else
	{
		VectorCopy (startpoint, spawnpoint);
		return true;
	}
}

// FIXME - all of this needs to be tweaked to handle the new gravity rules
// if we ever want to spawn stuff on the roof

//
// CheckSpawnPoint
//
// PMM - checks volume to make sure we can spawn a monster there (is it solid?)
//
// This is all fliers should need

qboolean CheckSpawnPoint (vec3_t origin, vec3_t mins, vec3_t maxs)
{
	trace_t	tr;

	if (!mins || !maxs || VectorCompare(mins, vec3_origin) || VectorCompare (maxs, vec3_origin))
	{
		return false;
	}

	tr = gi.trace (origin, mins, maxs, origin, NULL, MASK_MONSTERSOLID);
	if(tr.startsolid || tr.allsolid)
	{
//		if ((g_showlogic) && (g_showlogic->value))
//			gi.dprintf("createmonster in wall. removing\n");
		return false;
	}
	if (tr.ent != world)
	{
//		if ((g_showlogic) && (g_showlogic->value))
//			gi.dprintf("createmonster in entity %s\n", tr.ent->classname);
		return false;
	}	
	return true;
}

//
// CheckGroundSpawnPoint
//
// PMM - used for walking monsters
//  checks:
//		1)	is there a ground within the specified height of the origin?
//		2)	is the ground non-water?
//		3)	is the ground flat enough to walk on?
//

qboolean CheckGroundSpawnPoint (vec3_t origin, vec3_t entMins, vec3_t entMaxs, float height, float gravity)
{
	trace_t		tr;
	vec3_t		start, stop;
	int			failure = 0;
	vec3_t		mins, maxs;
	int			x, y;	
	float		mid, bottom;

	if (!CheckSpawnPoint (origin, entMins, entMaxs))
		return false;

	// FIXME - this is too conservative about angled surfaces

	VectorCopy (origin, stop);
	// FIXME - gravity vector
	stop[2] = origin[2] + entMins[2] - height;

	/*
	gi.WriteByte (svc_temp_entity);
	gi.WriteByte (TE_DEBUGTRAIL);
	gi.WritePosition (origin);
	gi.WritePosition (stop);
	gi.multicast (start, MULTICAST_ALL);
	*/

	tr = gi.trace (origin, entMins, entMaxs, stop, NULL, MASK_MONSTERSOLID | MASK_WATER);
	// it's not going to be all solid or start solid, since that's checked above

	if ((tr.fraction < 1) && (tr.contents & MASK_MONSTERSOLID))
	{
		// we found a non-water surface down there somewhere.  now we need to check to make sure it's not too sloped
		//
		// algorithm straight out of m_move.c:M_CheckBottom()
		//

		// first, do the midpoint trace

		VectorAdd (tr.endpos, entMins, mins);
		VectorAdd (tr.endpos, entMaxs, maxs);


		// first, do the easy flat check
		//
#ifdef ROGUE_GRAVITY
		// FIXME - this will only handle 0,0,1 and 0,0,-1 gravity vectors
		if(gravity > 0)
			start[2] = maxs[2] + 1;
		else
			start[2] = mins[2] - 1;
#else
		start[2] = mins[2] - 1;
#endif
		for	(x=0 ; x<=1 ; x++)
		{
			for	(y=0 ; y<=1 ; y++)
			{
				start[0] = x ? maxs[0] : mins[0];
				start[1] = y ? maxs[1] : mins[1];
				if (gi.pointcontents (start) != CONTENTS_SOLID)
					goto realcheck;
			}
		}

		// if it passed all four above checks, we're done
		return true;

realcheck:

		// check it for real

		start[0] = stop[0] = (mins[0] + maxs[0])*0.5;
		start[1] = stop[1] = (mins[1] + maxs[1])*0.5;
		start[2] = mins[2];

		tr = gi.trace (start, vec3_origin, vec3_origin, stop, NULL, MASK_MONSTERSOLID);

		if (tr.fraction == 1.0)
			return false;
		mid = bottom = tr.endpos[2];

#ifdef ROGUE_GRAVITY
		if(gravity < 0)
		{
			start[2] = mins[2];
			stop[2] = start[2] - STEPSIZE - STEPSIZE;
			mid = bottom = tr.endpos[2] + entMins[2];
		}
		else
		{
			start[2] = maxs[2];
			stop[2] = start[2] + STEPSIZE + STEPSIZE;
			mid = bottom = tr.endpos[2] - entMaxs[2];
		}
#else
		stop[2] = start[2] - 2*STEPSIZE;
		mid = bottom = tr.endpos[2] + entMins[2];
#endif

		for	(x=0 ; x<=1 ; x++)
			for	(y=0 ; y<=1 ; y++)
			{
				start[0] = stop[0] = x ? maxs[0] : mins[0];
				start[1] = stop[1] = y ? maxs[1] : mins[1];
				
				/*
				gi.WriteByte (svc_temp_entity);
				gi.WriteByte (TE_DEBUGTRAIL);
				gi.WritePosition (start);
				gi.WritePosition (stop);
				gi.multicast (start, MULTICAST_ALL);	
				*/
				tr = gi.trace (start, vec3_origin, vec3_origin, stop, NULL, MASK_MONSTERSOLID);

//PGM
#ifdef ROGUE_GRAVITY
// FIXME - this will only handle 0,0,1 and 0,0,-1 gravity vectors
				if(gravity > 0)
				{
					if (tr.fraction != 1.0 && tr.endpos[2] < bottom)
						bottom = tr.endpos[2];
					if (tr.fraction == 1.0 || tr.endpos[2] - mid > STEPSIZE)
					{
//						if ((g_showlogic) && (g_showlogic->value))
//							gi.dprintf ("spawn - rejecting due to uneven ground\n");
						return false;
					}
				}
				else
				{
					if (tr.fraction != 1.0 && tr.endpos[2] > bottom)
						bottom = tr.endpos[2];
					if (tr.fraction == 1.0 || mid - tr.endpos[2] > STEPSIZE)
					{
//						if ((g_showlogic) && (g_showlogic->value))
//							gi.dprintf ("spawn - rejecting due to uneven ground\n");
						return false;
					}
				}
#else
				if (tr.fraction != 1.0 && tr.endpos[2] > bottom)
					bottom = tr.endpos[2];
				if (tr.fraction == 1.0 || mid - tr.endpos[2] > STEPSIZE)
					{
						return false;
					}
#endif
			}

		return true;		// we can land on it, it's ok
	}

	// otherwise, it's either water (bad) or not there (too far)
	// if we're here, it's bad below
//	if ((g_showlogic) && (g_showlogic->value))
//	{
//		if (tr.fraction < 1)
//			if ((g_showlogic) && (g_showlogic->value))
//				gi.dprintf("groundmonster would fall into water/slime/lava\n");
//		else
//			if ((g_showlogic) && (g_showlogic->value))
//				gi.dprintf("groundmonster would fall too far\n");
//	}

	return false;
}

void DetermineBBox (char *classname, vec3_t mins, vec3_t maxs)
{
	// FIXME - cache this stuff
	edict_t		*newEnt;

	newEnt = G_Spawn();

	VectorCopy(vec3_origin, newEnt->s.origin);
	VectorCopy(vec3_origin, newEnt->s.angles);
	newEnt->classname = ED_NewString (classname);
	newEnt->monsterinfo.aiflags |= AI_DO_NOT_COUNT;
	
	ED_CallSpawn(newEnt);
	
	VectorCopy (newEnt->mins, mins);
	VectorCopy (newEnt->maxs, maxs);

	G_FreeEdict (newEnt);
}

// ****************************
// SPAWNGROW stuff
// ****************************

#define SPAWNGROW_LIFESPAN		0.3

void spawngrow_think (edict_t *self)
{
	int i;

	for (i=0; i<2; i++)
	{
			self->s.angles[0] = rand()%360;
			self->s.angles[1] = rand()%360;
			self->s.angles[2] = rand()%360;
	}
	if ((level.time < self->wait) && (self->s.frame < 2))
		self->s.frame++;
	if (level.time >= self->wait)
	{
		if (self->s.effects & EF_SPHERETRANS)
		{
			G_FreeEdict (self);
			return;
		}
		else if (self->s.frame > 0)
			self->s.frame--;
		else
		{
			G_FreeEdict (self);
			return;
		}
	}
	self->nextthink += FRAMETIME;
}

void SpawnGrow_Spawn (vec3_t startpos, int size)
{
	edict_t *ent;
	int	i;
	float	lifespan;

	ent = G_Spawn();
	VectorCopy(startpos, ent->s.origin);
	for (i=0; i<2; i++)
	{
			ent->s.angles[0] = rand()%360;
			ent->s.angles[1] = rand()%360;
			ent->s.angles[2] = rand()%360;
	}
	ent->solid = SOLID_NOT;
//	ent->s.renderfx = RF_FULLBRIGHT | RF_IR_VISIBLE;
	ent->s.renderfx = RF_IR_VISIBLE;
	ent->movetype = MOVETYPE_NONE;
	ent->classname = "spawngro";

	if (size <= 1)
	{
		lifespan = SPAWNGROW_LIFESPAN;
		ent->s.modelindex = gi.modelindex("models/items/spawngro2/tris.md2");
	}
	else if (size == 2)
	{
		ent->s.modelindex = gi.modelindex("models/items/spawngro3/tris.md2");
		lifespan = 2;
	}
	else
	{
		ent->s.modelindex = gi.modelindex("models/items/spawngro/tris.md2");
		lifespan = SPAWNGROW_LIFESPAN;
	}

	ent->think = spawngrow_think;

	ent->wait = level.time + lifespan;
	ent->nextthink = level.time + FRAMETIME;
	if (size != 2)
		ent->s.effects |= EF_SPHERETRANS;
	gi.linkentity (ent);
}
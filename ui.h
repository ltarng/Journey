#ifndef UI_PRINT_CLEAR_H__
#define UI_PRINT_CLEAR_H__
void blank(const int blank,const int pause,const int change_line,const int blank2);
void npc_dialogue(char *words[],const int dialogue_size);
void battle_star();
void event_star();
void map_icon(int (*p)[22],int *rx,int *ry,int *section);
void clear(const int i_size,const int j,const int j_size,const int x);
void clear_dialogue();
void clear_event(const int j);
void clear_battle_star(const int j);
void print_role_monster_hpmp(const int *php,const int *pmp,int *monster_hp,const char monster_name[][30],const int monster_num);
#endif // UI_PRINT_CLEAR_H__

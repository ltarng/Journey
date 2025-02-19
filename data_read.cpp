#include"console.h"

void create_player(all_player *allp){
    for(int i=0; i<status_num; i++){
        allp -> player[i].hp = 30 + 30 * i;
        allp -> player[i].atk = 5 + 7 * i;
    }
}

void read_monster(all_monster *allm){
    FILE *fop=fopen("monster.txt","r");
    char c=' ';
    if(fop==0) return;
    for(int i=0; i<mon_num; i++){
        fgets(allm->monsters[i].name, mon_name_len, fop);/*include '\n'*/
        for(int j=0; j<mon_name_len; j++) if(allm->monsters[i].name[j]=='\n') allm->monsters[i].name[j]='\0';
        fscanf(fop,"%d %d %d", &allm->monsters[i].level, &allm->monsters[i].hp, &allm->monsters[i].atk);
        fscanf(fop," %*c%*c");
    }
}

void read_map(const int size, char name[30],int map[22][22]){
    FILE *fmap = fopen(name,"r");
    if(fmap==0) return;//end
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            fscanf(fmap, "%d", &map[i][j]);//1=sand, 7=Ti-Zi, 100=NPC
        }
    }
    fclose(fmap);
}


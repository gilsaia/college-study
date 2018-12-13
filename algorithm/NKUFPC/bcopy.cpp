#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

struct Status
{
    bool ac;
    time_t sub_time;
    bool operator<(const Status &rhs) const
    {
        return sub_time < rhs.sub_time;
    }
};

struct Player
{
    char name[100];
    Status st[15][100]; //status[question][sumbit]
    int cnt[15];        //submit number of each question
    int ac_num;
    long long sum_time;
    bool operator<(const Player &rhs) const
    {
        if (ac_num != rhs.ac_num)
            return ac_num > rhs.ac_num;
        else if (sum_time != rhs.sum_time)
            return sum_time > rhs.sum_time;
        else
            return strcmp(name, rhs.name) > 0;
    }
    Player() : ac_num(0), sum_time(0)
    {
        memset(name, 0, sizeof(name));
        memset(st, 0, sizeof(st));
        memset(cnt, 0, sizeof(cnt));
    }
};

struct Question
{
    int ac_num;
    int sub_num;
    int fast_time;
    char fast_player[100];
    Question() : ac_num(0), sub_num(0), fast_time(0x7fffffff), fast_player("") {}
};

Player players[500];
Question questions[15];
map<string, int> player_id;
int all_kill;

int parser(char s[], char ch, int &tag_1, int &tag_2)
{
    tag_2 = strchr(s, ch) - s;
    char tmp[5] = "";
    strncpy(tmp, s, tag_2);
    tag_1 += tag_2 + 1;
    return atoi(tmp);
}

time_t get_time()
{
    char ymd[20], hms[20]; //year_month_day, hour_minute_second;
    scanf("%s%s", ymd, hms);
    ymd[strlen(ymd)] = '-';
    hms[strlen(hms)] = ':';
    struct tm *t;
    time_t rawtime = 0;
    //time(&rawtime);
    t = localtime(&rawtime);
    int tag_1 = 0, tag_2 = 0;
    t->tm_year = (parser(ymd + tag_1, '-', tag_1, tag_2) - 1900) % 137;
    t->tm_mon = parser(ymd + tag_1, '-', tag_1, tag_2) - 1;
    t->tm_mday = parser(ymd + tag_1, '-', tag_1, tag_2);
    tag_1 = tag_2 = 0;
    t->tm_hour = parser(hms + tag_1, ':', tag_1, tag_2) - 1;
    t->tm_min = parser(hms + tag_1, ':', tag_1, tag_2) - 1;
    t->tm_sec = parser(hms + tag_1, ':', tag_1, tag_2) - 1;
    return mktime(t);
}

time_t get_finish_time(time_t start_time)
{
    char last_time[10];
    scanf("%s", last_time);
    int tag_1 = 0, tag_2 = 0;
    int hour = parser(last_time, ':', tag_1, tag_2) - 1;
    int min = parser(last_time, ':', tag_1, tag_2) - 1;
    int sec = parser(last_time, ':', tag_1, tag_2) - 1;
    time_t res = start_time + 3600 * hour + 60 * min + sec;
    return res;
}

int get_id(string &name)
{
    if (player_id.count(name))
        return player_id[name];
    else
        return player_id[name] = player_id.size();
}

int main()
{
    int N, K;
    scanf("%d%d", &N, &K);
    time_t start_time = get_time();
    time_t finish_time = get_finish_time(start_time);

    for (int i = 0; i < N; i++)
    {
        char t[20], name[100], question[2], state[4];
        scanf("%s%s%s%s%s%s%s%s", t, name, question, state, t, t, t, t);
        time_t sub_time = get_time();
        if ((sub_time < start_time) || (sub_time > finish_time))
        {
            continue;
        }
        string name_s = name;
        int p_id = get_id(name_s); 
        //Avoid to record someone in the ranklist who did not submit during the contest;
        if ((strcmp(state, "SE") == 0))
        { //SE don't have a penalty;
            continue;
        }
        else
        {
            Player &p = players[p_id];
            strcpy(p.name, name);
            int q_id = question[0] - 'A';
            int cnt = p.cnt[q_id]++;
            p.st[q_id][cnt].ac = !strcmp(state, "AC");
            p.st[q_id][cnt].sub_time = sub_time;
        }
    }

    for (int i = 0; i < player_id.size(); i++)
    { //i-th player
        Player &p = players[i];
        for (int j = 0; j < K; j++)
        { //j-th question
            sort(p.st[j], p.st[j] + p.cnt[j]);
            Question &q = questions[j];
            bool ac = false;
            for (int k = 0; k < p.cnt[j]; k++)
            { //k-th submit
                Status &s = p.st[j][k];
                q.sub_num++;
                if (s.ac)
                {
                    p.ac_num++;
                    q.ac_num++;
                    if (!ac)
                        p.sum_time += s.sub_time + k * 20 * 60;
                    if (s.sub_time < q.fast_time)
                    {
                        q.fast_time = s.sub_time;
                        strcpy(q.fast_player, p.name);
                    }
                    ac = true;
                }
            }
        }
        all_kill += (p.ac_num == K);
    }
    sort(players, players + player_id.size());

    for (int i = 0; i < player_id.size(); i++)
    {
        printf("rank #%d:%s\n", i + 1, players[i].name);
    }
    for (int i = 0; i < K; i++)
    {
        Question &q = questions[i];
        printf("%c(%d/%d):\n", 'A' + i, q.ac_num, q.sub_num);
        printf("%s\n", q.ac_num ? q.fast_player : "NULL");
    }
    printf("%d\n", all_kill);
    for (int i = 0; i < player_id.size(); i++)
    {
        if (players[i].ac_num == K)
            printf("%s\n", players[i].name);
    }
    return 0;
}
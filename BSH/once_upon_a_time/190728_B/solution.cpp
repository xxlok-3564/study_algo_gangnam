#define MAX_USER 1000
#define MAX_MOVIE 5000
#define MAX_WATCH 5000

const int hash_size = MAX_MOVIE * 5;
int hash_table[hash_size][20];

struct user {
    bool movie_ox[MAX_WATCH]; //index 입력됨
    int watch_movie_list[MAX_WATCH]; //MID 입력됨
    int movie_count;
};

struct movie {
    int mid;
    int watcher_list[MAX_USER];
    int watcher_count;
};

user user_list[MAX_USER];
int user_count;
movie movie_list[MAX_MOVIE];
int movie_count;

unsigned get_hash_key(int mid) {
    unsigned hash_key = 0;
    unsigned base = 1;
    const unsigned PRIME = 17;

    while (mid) {

        hash_key += (base * (mid % 10));
        base *= PRIME;

        mid /= 10;
    }

    hash_key %= hash_size;

    return hash_key;
}

void insert_movie(int mid, int index) {

    unsigned hash_key = get_hash_key(mid);
    int size = hash_table[hash_key][0];
    hash_table[hash_key][size + 1] = index;

    hash_table[hash_key][0] += 1;
}

int get_index(int mid) {

    unsigned hash_key = get_hash_key(mid);
    int size = hash_table[hash_key][0];
    for (int i = 1; i <= size; i++) {
        int idx = hash_table[hash_key][i];
        if (movie_list[idx].mid == mid)
            return idx;
    }

    return -1;
}

void init() {

    user_count = 0;
    movie_count = 0;
    for (int i = 0; i < hash_size; i++) {
        hash_table[i][0] = 0;
    }

}

void addUser(int uid) {
    user_list[uid].movie_count = 0;
    for (int i = 0; i < MAX_WATCH; i++)
        user_list[uid].movie_ox[i] = false;
    user_count += 1;
}

void addMovie(int mid) {
    movie_list[movie_count].mid = mid;
    movie_list[movie_count].watcher_count = 0;

    insert_movie(mid, movie_count);

    movie_count += 1;
}

void watchMovie(int uid, int mid) {

    int movie_idx = get_index(mid);

    user_list[uid].watch_movie_list[user_list[uid].movie_count] = mid;
    user_list[uid].movie_ox[movie_idx] = true;
    user_list[uid].movie_count += 1;

    movie_list[movie_idx].watcher_list[movie_list[movie_idx].watcher_count] = uid;
    movie_list[movie_idx].watcher_count += 1;

}

struct user_score {
    int matched_movie;
    int how_many_watch;
    int uid;
};
struct movie_score {
    int mid;
    int watchers;
    int version;
};

bool user_score_cmp(const user_score &a, const user_score &b) {

    if (a.matched_movie == b.matched_movie) {

        if (a.how_many_watch == b.how_many_watch)
            return a.uid > b.uid;

        return a.how_many_watch < b.how_many_watch;
    }

    return a.matched_movie < b.matched_movie;
}

void user_score_sort(user_score *arr, user_score *buf, const int left, const int right) {

    if (right - left <= 1)
        return;

    int mid = (left + right) / 2;

    user_score_sort(arr, buf, left, mid);
    user_score_sort(arr, buf, mid, right);

    int l = left;
    int r = mid;
    int idx = left;

    while (l < mid && r < right) {
        if (user_score_cmp(arr[l], arr[r])) {
            buf[idx] = arr[r];
            idx++;
            r++;
        } else {
            buf[idx] = arr[l];
            idx++;
            l++;
        }
    }

    while (l < mid) {
        buf[idx] = arr[l];
        l++;
        idx++;
    }

    while (r < right) {
        buf[idx] = arr[r];
        r++;
        idx++;
    }

    for (int i = left; i < right; i++)
        arr[i] = buf[i];
}

bool movie_score_cmp(const movie_score &a, const movie_score &b) {

    if (a.watchers == b.watchers)
        return a.version < b.version;

    return a.watchers < b.watchers;
}

void movie_score_sort(movie_score *arr, movie_score *buf, const int left, const int right) {
    if (right - left <= 1)
        return;

    int mid = (left + right) / 2;

    movie_score_sort(arr, buf, left, mid);
    movie_score_sort(arr, buf, mid, right);

    int l = left;
    int r = mid;
    int idx = left;

    while (l < mid && r < right) {
        if (movie_score_cmp(arr[l], arr[r])) {
            buf[idx] = arr[r];
            idx++;
            r++;
        } else {
            buf[idx] = arr[l];
            idx++;
            l++;
        }
    }

    while (l < mid) {
        buf[idx] = arr[l];
        l++;
        idx++;
    }

    while (r < right) {
        buf[idx] = arr[r];
        r++;
        idx++;
    }

    for (int i = left; i < right; i++)
        arr[i] = buf[i];
}

int recommandMovie(int uid) {

    user_score user_score_list[MAX_USER];
    user_score user_score_buf[MAX_USER];

    movie_score movie_score_list[MAX_MOVIE];
    movie_score movie_score_buf[MAX_MOVIE];

    //user_score 정렬
    for (int i = 0; i < user_count; i++) {
        user_score_list[i].how_many_watch = user_list[i].movie_count;
        user_score_list[i].uid = i;
    }

    //user의 movie 리스트에서 movie를 조회하고, 해당 movie가 가지고 있는 user를 조회하여 score를 지정
    for (int i = 0; i < user_list[uid].movie_count; i++) {
        int movie_idx = get_index(user_list[uid].watch_movie_list[i]);
        for (int j = 0; j < movie_list[movie_idx].watcher_count; j++) {
            if (movie_list[movie_idx].watcher_list[j] != uid) {
                user_score_list[movie_list[movie_idx].watcher_list[j]].matched_movie += 1;
            }
        }
    }

    user_score_sort(user_score_list, user_score_buf, 0, user_count);

    int num_group;
    if (user_list[uid].movie_count < 100)
        num_group = 1;
    else
        num_group = user_list[uid].movie_count / 100;

    for (int i = 0; i < movie_count; i++) {
        movie_score_list[i].mid = movie_list[i].mid;
        movie_score_list[i].version = i;
        movie_score_list[i].watchers = 0;
    }

    //앞에 해당되는 사람들을 조회하여서 해당 영화에다가 본 사람 수 증가

    for (int i = 0; i < num_group; i++) {
        int candidate_uid = user_score_list[i].uid;
        for (int j = 0; j < user_list[candidate_uid].movie_count; j++) {
            int midx = get_index(user_list[candidate_uid].watch_movie_list[j]);
            movie_score_list[midx].watchers += 1;
        }
    }

    movie_score_sort(movie_score_list, movie_score_buf, 0, movie_count);

    for (int i = 0; i < movie_count; i++) {
        if (movie_score_list[i].watchers == 0)
            break;
        int midx = get_index(movie_score_list[i].mid);
        if (!(user_list[uid].movie_ox[midx]))
            return movie_score_list[i].mid;
    }

    return -1;
}
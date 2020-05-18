#define SetLength2(a, n, t) a=((t*) calloc(n, sizeof(t))) + (n)/2
int n, m, cnt, *Color, *Num, *Low; // Color 1=False, 2=True
vector<int> * a; //
stack<int> st;
bool Invalid=false;

bool minimize(int &a, int b) {
    if (a>b) a=b; else return false; return true;
}

void init(int m, int n){
    SetLength2(a, n*2+5, vector<int>);
    SetLength2(Color, n*2+5, int);
    SetLength2(Num, n*2+5, int);
    SetLength2(Low, n*2+5, int);
    Invalid = false;
}

void set_color(int u, int x){
    if (Color[u]==(x^3)) Invalid=true; else Color[u]=x;
    if (Color[-u]==x) Invalid=true; else Color[-u]=(x^3);
}

void tarzan(int u){
    Num[u]=Low[u]=++cnt; st.push(u);

    for (int i=0,v; v=a[u][i]; i++){
        if (Num[v]) minimize(Low[u], Num[v]);
        else tarzan(v), minimize(Low[u], Low[v]);
        if (Color[v]==1) set_color(u, 1); // False
    }
    if (Low[u]==Num[u]){
        int v=0;
        if (Color[u]==0) set_color(u, 2); // True
        do {
            v=st.top(); st.pop();
            set_color(v, Color[u]);
            Num[v]=Low[v]=0x33334444;
        } while (u!=v);
    }
}

void enter(){
    fori(i,1,m) {
        int p, q;
        cin >> p >> q;
        a[-p].push_back(q);
        a[-q].push_back(p);
    }
    fori(i,1,n) a[i].push_back(0);
    fori(i,1,n) a[-i].push_back(0);
}

void solve() {
    cin >> m >> n;
    init(m, n);
    enter();
    fori(i,1,n) if (!Num[i]) tarzan(i);
    fori(i,1,n) if (!Num[-i]) tarzan(-i);
    if (Invalid) cout << "No" << endl;
    else {
        cout << "Yes" << endl;
        int Answer=0;
        fori(i,1,n) if (Color[i]==2) Answer++;
        cout << Answer;
        fori(i,1,n) if (Color[i]==2) cout << ' ' << i; cout << endl;
    }
}
import std;
string si(){ return readln(); }
int ni(){ return si.chomp.to!int; }
long bi(){ return si.chomp.to!long; }
double di(){ return si.chomp.to!double; }
string[] lsi(){ return si.split; }
int[] lni(){ return lsi.map!(to!int).array; }
long[] lbi(){ return lsi.map!(to!long).array; }
double[] ldi(){ return lsi.map!(to!double).array; }

void main() {
    const _=ni();
    auto s=si();
    writeln(s);
    int[] cnt=new int[10];
    foreach(const c;s) cnt[c.to!int]++;
    const n=s.sort!((a,b)=>b<a).to!long;
    int ans=0;
    for(long i=0; i*i<=n; ++i) {
        const t=(i*i).to!string;
    }
}
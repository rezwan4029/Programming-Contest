string S ;
vector<char>ret;
int len;
bool taken[10];

void back(){
    if(ret.size() == len ){
        rep(i,len)printf("%c",ret[i]);
        puts("");
        return ;
    }
    rep(i,len){
        if(!taken[i]){
            taken[i] = true , ret.push_back( S[i]);
            back();
            taken[i] = false , ret.pop_back();
        }
    }
}
int main(){
    S = "1234";
    len = S.size();
    back();
}

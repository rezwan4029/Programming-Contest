struct Node{
    int end;
    Node *next[ 128 ];
    Node(){
        end = 0 ;
        ms(next,NULL);
    }
}*root;

void insert(string s){
    Node *curr = root;
    int len = s.size();
    rep(i,len){
        if( curr->next[ s[i] ] == NULL  ){
            curr->next[ s[i] ] = new Node();
        }
        curr = curr->next[ s[i] ] ;
    }
    ++curr->end;
}

void remove(Node *curr){
    rep(i,128) if( curr->next[i] ) remove( curr->next[i] );
    delete(curr);
}

int search(string s ){
    Node *curr = root;
    int len = s.size();
    rep(i,len){
        if( curr->next[ s[i] ] == NULL ) return 0 ;
        curr = curr->next[ s[i] ];
    }
    return curr->end;
}

int main(){
    root = new Node();
}

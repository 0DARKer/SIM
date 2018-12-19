#include<iostream>
#include<vector>
#include<fstream>
#include<map>
#define SFT(STATE) {state=STATE;i++;break;}
#define SHIFT(CHAR,STATE) case CHAR: state=STATE;i++;break;
#define IN(BEGIN,END) (*i>=BEGIN&&*i<=END)
#define ELSE_SEVEN(EONE,ETWO) switch(*i){SHIFT(EONE,ETWO);default:if(IN('0','9')||IN('a','z')||IN('A','Z'))SFT(7)}break;
#define REBACK {b.push_back(make_pair(state,copy_v(j,i)));j=i;state=0;}
using namespace std;

vector<char> copy_v(vector<char>::iterator begin,vector<char>::iterator end);
void print_v(const vector<char> &);
void print_vp(const vector<pair<int,vector<char>>> &);
int main(){
    int state=0;
    vector<char> a;
    {
        ifstream fin("/home/darker/Programs/SIM/test.sim");
        char c;
        while((c=fin.get())!=EOF){
            a.push_back(c);
        }
    }
    vector<pair<int,vector<char>>> b;
    vector<char>::iterator i,j;
    j=i=a.begin();
    while(i<a.end()){
        switch(state){
        case 0:
            switch(*i){
            SHIFT('e',17)
            SHIFT('i',10)
            SHIFT('s',19)
            SHIFT('v',25)
            SHIFT('b',21)
            SHIFT(';',6)
            SHIFT(':',6)
            SHIFT('+',6)
            SHIFT('-',6)
            SHIFT('=',6)
            // SHIFT('\'',27)
            case '\'':
            	state=27;
            	i++;
            	b.push_back(make_pair(6,copy_v(j,i)));j=i;
            	break;
            case ' ':
           	case '\n':
           		i++;j++;break;
            default :
                if(IN('0','9')) SFT(8)
                else if(IN('a','z')||IN('A','Z'))SFT(7)
                else REBACK//如果没有匹配,则保存已经识别的字符串
            }
            break;
        case 8:
            if(IN('0','9'))SFT(8)
            break;
        case 27:
              switch(*i){
                case '\'':
                	state=9;
                	b.push_back(make_pair(state,copy_v(j,i-1)));
                	j=i;
                	i++;
                	break;
                default:
                	SFT(27)
                    // if(IN('0','9')||IN('a','z')||IN('A','Z'))SFT(27)
                   	// {b.push_back(make_pair(state,copy_v(j,i)));j=i;i++;break;}
            }
            break;
        case 10:
            ELSE_SEVEN('n',11)
        case 19:
            ELSE_SEVEN('t',20)
        case 25:
            ELSE_SEVEN('a',26)
        case 21:
            ELSE_SEVEN('e',22)
        case 17:
            ELSE_SEVEN('n',18)
        case 18:
              ELSE_SEVEN('d',3)
        case 11:
            ELSE_SEVEN('t',12)
        case 20:
              ELSE_SEVEN('r',4)
        case 26:
            ELSE_SEVEN('r',1)
        case 22:
              ELSE_SEVEN('g',23)
        case 12:
            ELSE_SEVEN('e',13)
        case 23:
              ELSE_SEVEN('i',24)
        case 24:
            ELSE_SEVEN('n',2)
        case 13:
              ELSE_SEVEN('r',14)
        case 14:
            ELSE_SEVEN('g',15)
        case 15:
              ELSE_SEVEN('e',16)
        case 16:
            ELSE_SEVEN('r',5)
        case 7:
            if(IN('0','9')||IN('a','z')||IN('A','Z'))SFT(7)
            else REBACK
            break;
        default:
        	if(state==9){b.push_back(make_pair(6,copy_v(j,i)));j=i;state=0;break;}
        	REBACK
        	break;
        }
    }
    print_vp(b);
}

vector<char> copy_v(vector<char>::iterator begin,vector<char>::iterator end){
    vector<char> re;
    vector<char>::iterator i;
    for(i=begin;i<end;i++){
        re.push_back(*i);
    }
    return re;

}
void print_v(const vector<char>& a){
	for(const char & i:a)
		cout << i;
}
void print_vp(const vector<pair<int,vector<char>>>& a){
	for(const pair<int,std::vector<char>> &v:a){
		cout << v.first<<": ";
		print_v(v.second);
		cout << endl;
	}
}
#include<iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    vector<int> v;
    int i, left, right;
    for(i=0; i<queue1.size(); ++i){
    	v.push_back(queue1[i]);
	}
	for(i=0; i<queue2.size(); ++i){
    	v.push_back(queue2[i]);
	}
	long long hap = 0, temp, goal;
	/*
	for(i=0; i<v.size(); ++i){
    	cout<<v[i]<<" ";
	}
	cout<<endl;
	*/
	for(i=0; i<v.size(); ++i){
    	hap+=(long long)(v[i]);
	}
	if(hap%2==1) return -1;
	goal = hap/2;
	left=0, right=0;
	temp = v[0];
	int left_end_index = queue1.size()-1,right_start_index = queue1.size(), temp_dap, dap = 30000000;
	while(left<=right&&right<v.size()){
		if(temp==goal){
			temp_dap = 0;
			if(left>=right_start_index){	//오른쪽 같에 있으면  
				temp_dap+=(left-right_start_index);
				if(left==v.size()-1){
					dap = min(dap, temp_dap);
					break;	
				} 
				temp_dap+=(right-left+1);
				temp_dap+=(left);
			}
			else{	//왼쪽에있으면 
				temp_dap+=left;
				if(right<left_end_index){	//이러면 다보내야함  
					temp_dap+=(right-left+1);
					temp_dap+=(queue2.size()+left);	
				}
				else{
					temp_dap+=(right-right_start_index+1);
				}
			}
			dap = min(dap, temp_dap);
			//cout<<left<<" "<<right<<endl;
			if(right==v.size()-1) break;
			
			temp-=v[left];
			left++;
			right++;
			temp+=v[right];
		}
		else if(temp<goal){
			if(right==v.size()-1) break;
			right++;
			temp+=v[right];
		}
		else{
			temp-=v[left];
			left++;
		}
	}
	if(dap == 30000000) return -1;
    return dap;
}

int main(void)
{
	int size1, size2;
	cin>>size1;
	int i, num;
	vector<int> v1;
	vector<int> v2;
	for(i=0; i<size1; ++i){
		cin>>num;
		v1.push_back(num);
	}
	cin>>size2;
	for(i=0; i<size2; ++i){
		cin>>num;
		v2.push_back(num);
	}
	cout<<solution(v1, v2);
	return 0;
}

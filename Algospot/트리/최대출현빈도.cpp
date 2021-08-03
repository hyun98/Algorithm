/*
정렬된 정수 수열 A[]가 주어졌을 때 주어진 구간의 최대 출현 빈도를 계산해보자
최대 출현 빈도 : 이 수열에서 가장 자주 등장하는 수의 출현 횟수
ex1) {1,1,1,2} 의 최대 출현 빈도는 3, {1,2,3}의 최대 출현 빈도는 1
ex2) A = {0,0,1,1,1,1,2,3,3,3,4} A[1] ~ A[5]까지 가장 많이 등장하는 수를 구하라고 하면 1이고 총 4번 등장한다.
A[5] ~ A[7] 에는 1,2,3이 각각 한 번씩 등장하므로 최대 출현 빈도는 1이다.

왼쪽 구간의 최대 출현 빈도와 오른쪽 구간의 최대 출현 빈도 중 더 큰값을 무조건 취할 수 있을까? - X

예외1 : 두 구간에서 가장 많이 출현하는 수가 같은 경우
왼쪽 부분 구간이 {1,2,2,2}, 오른쪽 부분 구간이 {2,2,2,3} 이라면 두 답 중 큰 값을 반환하는게 아닌 두 답의 합을 반환해야 한다.

예외2 : 두 구간을 이어보면 가장 많이 출현하는 수가 바뀌는 경우
왼쪽 부분 구간이 {1,1,1,2,2}, 오른쪽 부분 구간이 {2,2,3,3,3} 이라고 하자.
양쪽 부분 구간에서 가장 많이 출현하는 수는 1, 3이지만 두 구간을 합치면 2가 네 번으로 가장 많이 출현한다.

문제의 답 만이 아니라 두 개의 답을 합치는데 필요한 추가 정보도 계산해서 반환할 필요가 있다.

정렬된 수열 A[]라고 했기 때문에 두 개의 예외 상황에 대해서 
왼쪽 구간의 오른쪽 끝 수와 오른쪽 구간의 왼쪽 끝 수가 같은 점을 이용해서 모든 구간에 대해 답을 계산할 때 
왼쪽 끝 수와 오른쪽 끝 수 그리고 그들의 갯수를 함께 계산하자.

왼쪽 구간의 오른쪽 끝 숫자와 오른쪽 구간의 왼쪽 끝 숫자가 같은 경우 
이들을 합쳐보고 최대 출현 빈도가 바뀌는지 확인하면 된다.
*/

struct SECTION{
    int size;  // 구간의 크기
    int frequent;  // 가장 많이 등장하는 숫자의 출현 횟수
    int leftnum, rightnum;  // 왼쪽 끝, 오른쪽 끝 숫자
    int leftfreq, rightfreq;  // 왼쪽 끝, 오른쪽 끝 숫자의 출현 횟수
};

SECTION getQuery(SECTION &left, SECTION &right){
    SECTION ret;
    ret.size = left.size + right.size;
    
    ret.leftnum = left.leftnum;
    ret.leftfreq = left.leftfreq;
    if(left.size == left.leftfreq && left.leftnum == right.leftnum){
        ret.leftfreq += right.leftfreq;
    }
    
    ret.rightnum = right.rightnum;
    ret.rightfreq = right.rightnum;
    if(right.size == right.rightfreq && right.rightnum == left.rightnum){
        ret.rightfreq += left.rightfreq;
    }
    
    ret.frequent = max(left.frequent, right.frequent);
    
    if(left.rightnum == right.leftnum){
        ret.frequent = max(ret.frequent, left.rightfreq + right.leftfreq);
    }
    
    return ret;
}
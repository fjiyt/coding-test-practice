// 완전탐색 : 모든 경우의 수를 계산하는 방법. 

// [문제] 친구가 생각하고 있을 가능성이 높은 숫자의 개수 맞추기
// 해결법 -> 1. 불필요한 경우의 수 제거 / 2. 경우의 수 모두 확인하면서 스트라이크, 볼 개수 일치한 경우 찾기

const input = [
    [123,1,1],
    [356,1,0],
    [327,2,0],
    [489,0,1],
];

const answer = [];

for(let i = 123; i<=987; i++)
{
    const temp = String(i);

    if(temp.includes('0') || temp[0] === temp[1] || temp[1]===temp[2] || temp[2]===temp[0]) continue;

    answer.push(temp);
}

input.forEach((data) => {
    const temp = String(data[0]);

    for(let i = answer.length-1; i>=0; i--)
    {
        let [strike, ball] = [0,0];
        for(let j=0; j<3; j++)
        {
            if(answer[i][j] === temp[j]) strike++;
            if(answer[i][(j+1)%3] === temp[j] || answer[i][(j+2)%3]===temp[j]) ball++;
        }

        if(strike !== data[1] || ball !== data[2]) answer.splice(i,1);
    }
});
console.log(answer);
console.log(answer.length);
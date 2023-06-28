const memo = Array.from({length:1000});

function fibo(n) {
    if(n===1||n===2) return 1;
    if(memo[n]) return memo[n];
    else {
        memo[n] = fibo(n-1) + fibo(n-2);
        return memo[n];
    }
}

console.log(fibo(100));

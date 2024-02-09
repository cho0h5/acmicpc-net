fn getnum() -> i32 {
    let mut x = String::new();
    std::io::stdin().read_line(&mut x).unwrap();
    x.trim().parse().unwrap()
}

use std::cmp::max;

fn main() {
    let n = getnum();
    let mut arr1: Vec<i32> = vec![];
    let mut arr2: Vec<i32> = vec![];
    for _ in 0..n {
        let mut line = String::new();
        std::io::stdin().read_line(&mut line).unwrap();
        let mut line = line.split_whitespace();
        arr1.push(line.next().unwrap().parse().unwrap());
        arr2.push(line.next().unwrap().parse().unwrap());
    }
    let mut dp: Vec<i32> = vec![0; n as usize + 1];
    for i in 0..(n) {
        let i = i as usize;
        if i != 0 && dp[i] < dp[i - 1] {
            dp[i] = dp[i - 1];
        }
        if i + arr1[i] as usize <= n as usize {
            dp[i + arr1[i] as usize] = max(dp[i + arr1[i] as usize], arr2[i] + dp[i])
        }
    }
    println!("{}", max(dp[n as usize - 1], dp[n as usize]));
}

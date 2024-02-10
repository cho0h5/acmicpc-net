fn getnum() -> usize {
    let mut x = String::new();
    std::io::stdin().read_line(&mut x).unwrap();
    x.trim().parse().unwrap()
}

use std::cmp::max;

fn main() {
    let n = getnum();
    let mut arr = vec![];
    let mut line = String::new();
    std::io::stdin().read_line(&mut line).unwrap();
    for l in line.split_whitespace() {
        let x: i32 = l.parse().unwrap();
        arr.push(x);
    }
    let mut dp: Vec<i32> = vec![0; n];

    let mut m = 0;
    for i in 0..n {
        for j in 0..i {
            if arr[j] < arr[i] {
                dp[i] = max(dp[j], dp[i]);
            }
        }
        dp[i] += 1;
        m = max(m, dp[i]);
    }

//    println!("{:?}", arr);
//    println!("{:?}", dp);
    println!("{}", m);
}

fn getnum2() -> (i32, i32) {
    let mut x = String::new();
    std::io::stdin().read_line(&mut x).unwrap();
    let mut x = x.split_whitespace();
    let a = x.next().unwrap().trim().parse().unwrap();
    let b = x.next().unwrap().trim().parse().unwrap();
    (a, b)
}

fn getnum() -> i32 {
    let mut x = String::new();
    std::io::stdin().read_line(&mut x).unwrap();
    x.trim().parse().unwrap()
}

fn main() {
    let (n, k) = getnum2();
    let mut coins = vec![];
    for _ in 0..n {
        coins.push(getnum());
    }
    coins.sort();
    let mut dp: [[i32; k]; 100001];
    for (pos, e) in coins.iter().enumerate() {
        dp[e][pos] = 1;
    }

    for i in 0..k {

    }
}

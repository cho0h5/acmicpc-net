fn main() {
    let mut x = String::new();

    std::io::stdin().read_line(&mut x).unwrap();
    let x: u64 = x.trim().parse().unwrap();
    
    println!("{}", fib(x));
}

fn fib(n: u64) -> u64 {
    let mut a = 0;
    let mut b = 1;
    for _ in 0..n {
        a += b;
        let tmp = a;
        a = b % 1000000007;
        b = tmp % 1000000007;
    }

    a
}

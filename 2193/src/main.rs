fn getnum() -> u64 {
    let mut x = String::new();
    std::io::stdin().read_line(&mut x).unwrap();
    x.trim().parse().unwrap()
}

fn fib(n: u64) -> u64 {
    let mut x1 = 0;
    let mut x2 = 1;
    let mut tmp;

    for _ in 0..(n - 1) {
        tmp = x2;
        x2 += x1;
        x1 = tmp;
    }
    x2
}

fn main() {
    println!("{}", fib(getnum()));
}

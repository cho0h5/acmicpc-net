fn getnum() -> u64 {
    let mut x = String::new();
    std::io::stdin().read_line(&mut x).unwrap();
    x.trim().parse().unwrap()
}

fn main() {
    let n = getnum();
    let mut ret = 9;

    for _ in 0..(n - 1) {
        ret *= 2;
        ret -= 1;
        ret %= 1000000000;
    }
    println!("{}", ret);
}

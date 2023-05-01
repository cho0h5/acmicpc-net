fn main() {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    let s = s.trim().as_bytes();
    let mut b = 1;
    let mut acc = 0;
    for i in s {
        let a = i + 1 - 'a' as u8;
        let a = a as i64;
        let term = a * b % 1234567891;
        acc += term;
        b *= 31;
        b %= 1234567891;

    }
    println!("{}", acc % 1234567891);
}

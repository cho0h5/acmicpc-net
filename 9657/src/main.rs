fn getnum() -> u64 {
    let mut x = String::new();
    std::io::stdin().read_line(&mut x).unwrap();
    x.trim().parse().unwrap()
}

fn main() {
    let n = getnum();
    let mut v = vec![true, false, true, true, true];
    for i in 5..n as usize {
        if v[i - 1] == false || v[i - 3] == false || v[i - 4] == false {
            v.push(true);
        } else {
            v.push(false);
        }
    }
    // println!("{}", v[n as usize - 1]);
    if v[n as usize - 1] {
        println!("SK");
    } else {
        println!("CY");
    }
}

use std::io;
use std::fmt::Write;

fn hanoi(from: u32, mid: u32, to: u32, n: u32, output: &mut String) {
    if n == 1 {
        writeln!(output, "{} {}", from, to);
        return;
    }

    hanoi(from, to, mid, n - 1, output);
    writeln!(output, "{} {}", from, to);
    hanoi(mid, from, to, n - 1, output);
}

fn main() {
    let mut input = String::new();
    let mut output = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let n: u32 = input.trim().parse().unwrap();

    writeln!(output, "{}", 2_u32.pow(n) - 1);
    hanoi(1, 2, 3, n, &mut output);

    println!("{}", output);
}

use std::io::Read;
use std::fmt::Write;

fn main() {
    let mut input = String::new();
    std::io::stdin().read_to_string(&mut input).unwrap();
    let mut input = input.split('\n');
    let mut output = String::new();
    
    input.next();
    
    for line in input {
        let mut line = line.split_ascii_whitespace();
        let a: i32 = line.next().unwrap().parse().unwrap();
        let b: i32 = line.next().unwrap().parse().unwrap();
        writeln!(output, "{}", a + b);
    }
    println!("{}", output);
}
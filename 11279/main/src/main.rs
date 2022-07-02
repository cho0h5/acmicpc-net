use std::collections::BinaryHeap;
use std::io::Read;
use std::fmt::Write;

fn main() {
    let mut input = String::new();
    std::io::stdin().read_to_string(&mut input).unwrap();
    let mut input = input.split_ascii_whitespace();
    let mut output = String::new();
    
    input.next();
    
    let mut heap = BinaryHeap::new();
    for i in input {
        let n = i.parse::<i32>().unwrap();
        match n {
            0 => match heap.pop() {
                Some(e) => writeln!(output, "{}", e).unwrap(),
                _ => writeln!(output, "0").unwrap(),
            },
            x => heap.push(x),
        }
    }
    println!("{}", output);
}

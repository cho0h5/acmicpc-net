use std::collections::BinaryHeap;

fn read_int() -> i32 {
    let mut n = String::new();
    std::io::stdin().read_line(&mut n).unwrap();
    n.pop();
    n.parse::<i32>().unwrap()
}

fn main() {
    let mut heap = BinaryHeap::new();
    let n = read_int();
    
    for _ in 0..n {
        match read_int() {
            0 => match heap.pop() {
                Some(e) => println!("{}", e),
                _ => println!("0"),
            },
            x => heap.push(x),
        }
    }
}

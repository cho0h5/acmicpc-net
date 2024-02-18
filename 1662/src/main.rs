#[derive(Debug)]
enum Element {
    Digit(u64, u64),
    Lparen,
}

use Element::*;
use std::io::stdin;

fn main() {
    let mut line = String::new();
    let mut stack: Vec<Element> = vec![];
    stdin().read_line(&mut line).unwrap();

    for c in line.trim().chars() {
        match c {
            c if c.is_ascii_digit() => {
                let last = stack.pop();
                match last {
                    Some(Digit(digits, _)) => stack.push(Digit(digits + 1, c as u64 - '0' as u64)),
                    Some(Lparen) => {
                        stack.push(Lparen);
                        stack.push(Digit(1, c as u64 - '0' as u64));
                    }
                    _ => stack.push(Digit(1, c as u64 - '0' as u64)),
                }
            },
            '(' => {
                stack.push(Lparen);
            },
            ')' => {
                let last = stack.pop();
                match last {
                    Some(Digit(digits, _)) => {
                        stack.pop();
                        let last2 = stack.pop();
                        match last2 {
                            Some(Digit(0, _)) => {
                                stack.push(Digit(0, 0));
                            },
                            Some(Digit(digits2, mul2)) => {
                                stack.push(Digit(digits2 - 1 + mul2 * digits, 0));
                            },
                            _ => panic!("asd"),
                        }
                    },
                    Some(Lparen) => {
                        stack.pop();
                    }
                    _ => (),
                }
            },
            _ => (),
        }
        // println!("{:?}", stack);
    }
    if let Some(Digit(digits, _)) = stack.last() {
        println!("{}", digits);
    } else {
        println!("0");
    }
}

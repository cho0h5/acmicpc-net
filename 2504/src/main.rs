use std::io;
use std::process::exit;

use Elem::*;

#[derive(Debug)]
enum Elem {
    Lparen,
    Lbrace,
    Value(i32),
}

fn main() {
    let mut buffer = String::new();
    io::stdin().read_line(&mut buffer).unwrap();
    let mut s: Vec<Elem> = vec![];

    for c in buffer.trim().as_bytes() {
        let c = *c as char;

        match c {
            '(' => {
                s.push(Lparen);
            },
            '[' => {
                s.push(Lbrace);
            },
            ')' => {
                rparen(&mut s);
            },
            ']' => {
                rbrace(&mut s);
            },
            _ => end(),
        }
        // println!("{:?}", s);
        fold(&mut s);
        // println!("{:?}", s);
    }

    if s.len() != 1 {
        end();
    }
    match s.pop() {
        Some(Value(x)) => println!("{}", x),
        _ => end(),
    }
}

fn fold(s: &mut Vec<Elem>) {
    match s.pop() {
        Some(Value(x)) => {
            match s.pop() {
                Some(Value(y)) => {
                    s.push(Value(x + y));
                },
                Some(z) => {
                    s.push(z);
                    s.push(Value(x));
                },
                _ => s.push(Value(x)),
            }
        },
        Some(z) => s.push(z),
        _ => ()
    }
}

fn rparen(s: &mut Vec<Elem>) {
    match s.pop() {
        Some(Lparen) => {
            s.push(Value(2));
        },
        Some(Value(x)) => {
            match s.pop() {
                Some(Lparen) => (),
                _ => end(),
            }
            s.push(Value(x * 2));
        },
        _ => end(),
    }
}

fn rbrace(s: &mut Vec<Elem>) {
    match s.pop() {
        Some(Lbrace) => {
            s.push(Value(3));
        },
        Some(Value(x)) => {
            match s.pop() {
                Some(Lbrace) => (),
                _ => end(),
            }
            s.push(Value(x * 3));
        },
        _ => end(),
    }
}

fn end() {
    println!("0");
    exit(0);
}

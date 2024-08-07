use std::io;

fn sol(s: &str, t: &str) -> bool {
    if s == t {
        return true;
    } else if s.len() > t.len() {
        return false;
    }

    if let Some(last_char) = t.chars().last() {
        if last_char == 'A' {
            // println!("debug A: {}", &t[..t.len() - 1]);
            if sol(s, &t[..t.len() - 1]) {
                return true;
            }
        }
    }

    if t.chars().next().unwrap() == 'B' {
        let mut chars = t.chars();
        chars.next();
        if sol(s, &chars.rev().collect::<String>()) {
            return true;
        }
    }
    return false;
}

fn main() {
    let mut s = String::new();
    let mut t = String::new();

    io::stdin().read_line(&mut s).unwrap();
    io::stdin().read_line(&mut t).unwrap();

    let s = s.trim();
    let t = t.trim();

    if sol(s, t) {
        println!("{}", 1);
    } else {
        println!("{}", 0);
    }
}

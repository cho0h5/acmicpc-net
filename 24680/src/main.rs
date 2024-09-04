fn repeat(output: &mut String, s: &str, n: u32) {
    for _ in 0..n {
        output.push_str(s);
    }
}

fn main() {
    let mut output = String::new();

    // ㄹ
    for _ in 0..7 {
        output.push_str("DR");
        repeat(&mut output, "rFr", 14);
        output.push_str("DL");
        repeat(&mut output, "lFl", 14);
    }
    output.push_str("DR");
    repeat(&mut output, "rFr", 14);

    
    // ㄷ
    repeat(&mut output, "uFu", 15);
    repeat(&mut output, "lFl", 15);
    repeat(&mut output, "dFd", 15);

    println!("{output}");
}

use std::io;

fn main() {
    let mut scores: Vec<f64> = vec![];

    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let len: usize = input.trim().parse().unwrap();

    for _ in 0..len {
        let mut input = String::new();
        io::stdin().read_line(&mut input).unwrap();
        let score: f64 = input.trim().parse().unwrap();
        scores.push(score);
    }

    scores.sort_by(|a, b| a.partial_cmp(b).unwrap());

    for score in &scores[..7] {
        println!("{:.3}", score);
    }
}

fn getnum() -> usize {
    let mut x = String::new();
    std::io::stdin().read_line(&mut x).unwrap();
    x.trim().parse().unwrap()
}

fn findmax(arr: &[i32], arr2: &[i32], index: usize) -> i32 {
    let mut max = 0;
    for i in 0..index {
        if arr[i] < arr[index] && max < arr2[i] {
            max = arr2[i];
        }
    }
    return max;
}

fn main() {
    let n = getnum();
    let mut arr = vec![];
    let mut line = String::new();
    std::io::stdin().read_line(&mut line).unwrap();
    for l in line.split_whitespace() {
        let x: i32 = l.parse().unwrap();
        arr.push(x);
    }
    let mut arr2: Vec<i32> = vec![0; n];
    arr2[0] = arr[0];

    let mut max = arr2[0];
    for i in 1..n {
        arr2[i] = arr[i] + findmax(&arr, &arr2, i);

        if max < arr2[i] {
            max = arr2[i];
        }
    }
//    println!("{:?}", arr);
//    println!("{:?}", arr2);
    println!("{}", max);
}

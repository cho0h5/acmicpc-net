fn getnum() -> usize {
    let mut x = String::new();
    std::io::stdin().read_line(&mut x).unwrap();
    x.trim().parse().unwrap()
}

fn findmin(arr: &[i32], index: usize) -> isize {
    for i in (0..index).rev() {
        if arr[index] > arr[i] {
            return i as isize;
        }
    }
    return -1;
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
    // println!("{:?}", arr);
    let mut arr2: Vec<i32> = vec![0; n];
    arr2[0] = arr[0];

    let mut max = arr2[0];
    for i in 1..n {
        let min_i = findmin(&arr, i);
        if min_i == -1
        {
            arr2[i] = arr[i];
        } else {
            arr2[i] = arr2[min_i as usize] + arr[i];
        }
        if max < arr2[i] {
            max = arr2[i];
        }
    }
    println!("{}", max);
}

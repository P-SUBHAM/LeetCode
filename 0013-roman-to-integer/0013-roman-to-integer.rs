use std::collections::HashMap;

impl Solution {
    pub fn roman_to_int(s: String) -> i32 {
        let mut result = 0;
        let mut map = HashMap::new();
        map.insert('I', 1);
        map.insert('V', 5);
        map.insert('X', 10);
        map.insert('L', 50);
        map.insert('C', 100);
        map.insert('D', 500);
        map.insert('M', 1000);

        for (i, c) in s.chars().enumerate() {
            if i < s.len() - 1 && map[&c] < map[&s.chars().nth(i + 1).unwrap()] {
                result -= map[&c];
            } else {
                result += map[&c];
            }
        }

        result
    }
}
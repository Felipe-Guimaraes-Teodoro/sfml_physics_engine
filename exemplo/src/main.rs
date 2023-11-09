fn main() {
    println!("Hello, world!");
    let resultado = oi(3.0, 2.0);
    dbg!(resultado);
}

fn oi(
    valor: f32,
    valor2: f32,
) -> f32 {
    valor + valor2
}


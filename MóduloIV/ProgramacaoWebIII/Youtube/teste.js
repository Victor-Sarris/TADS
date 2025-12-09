function soma20A(x){
    return new Promise((resolve, reject)=>{
        setTimeout(() => {
            resolve(x + 20)
        }, 3000);
    })
}

async function chamSoma(x) {
    try{
        const resultado = await soma20A(x)
        console.log(resultado)
    }catch(erro){
        console.log(erro)
    }
}

chamSoma(10)
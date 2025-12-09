import {createLoan, 
    findAllLoans, 
    update,
    deleteLoanById} from "./loan.service.js"

//CREATE
export const newLoan = async (req, res) => {
    try{
        await createLoan(req.body)
        res.status(201).json({message: "Empréstimo cadastrado."})
    }catch(erro){
        res.status(502).json({erro: `${erro}`})
    }
}
//READ 
export const listLoans = async (req, res) =>{
    try{
        const loans = await findAllLoans()
        if(!loans){
            return res.status(404).json({message: "Não há registros."})
        }
        res.status(200).json({message: "Lista carregada com sucesso. ", loans})
    }catch(erro){
        res.status(500).json({message:  `Erro interno:( \n${erro}`})
    }
}

export const updateLoan = async (req, res) =>{
    try{
        const loan = req.body
        await update(loan)
        res.status(200).json({message: "Empréstimo atualizado com sucesso."})
    }catch(erro){
        res.status(400).json({message:  `Erro:( \n${erro}`})
    }
}

export const deleteLoan = async (req, res) =>{
    try{
        const { id } = req.body; 
        if (!id) {
            return res.status(400).json({ message: "ID do empréstimo é obrigatório para deletar." });
        }
        const deletedRows = await deleteLoanById(id);
        if (deletedRows === 0) {
            return res.status(404).json({ message: `Empréstimo com ID ${id} não encontrada para exclusão.` });
        }
        return res.status(200).json({message: "Empréstimo deletado permanentemente com sucesso."});
    }catch(erro){
        return res.status(500).json({message: `Erro interno ao tentar deletar: \n${erro.message}`})
    }
}
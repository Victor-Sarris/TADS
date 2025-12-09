import {createPerson, 
    findAllPersons, 
    update,
    deletePersonById} from "./person.service.js"

//CREATE
export const newPerson = async (req, res) => {
    try{
        await createPerson(req.body)
        res.status(201).json({message: "Pessoa cadastrada."})
    }catch(erro){
        res.status(502).json({erro: `${erro}`})
    }
}
//READ 
export const listPersons = async (req, res) =>{
    try{
        const persons = await findAllPersons()
        if(!persons){
            return res.status(404).json({message: "Não há registros."})
        }
        res.status(200).json({message: "Lista carregada com sucesso. ", persons})
    }catch(erro){
        res.status(500).json({message:  `Erro interno:( \n${erro}`})
    }
}

export const updatePerson = async (req, res) =>{
    try{
        const person = req.body
        await update(person)
        res.status(200).json({message: "Pessoa atualizada com sucesso."})
    }catch(erro){
        res.status(400).json({message:  `Erro:( \n${erro}`})
    }
}

export const deletePerson = async (req, res) =>{
    try{
        const { id } = req.body; 
        if (!id) {
            return res.status(400).json({ message: "ID da pessoa é obrigatório para deletar." });
        }
        const deletedRows = await deletePersonById(id);
        if (deletedRows === 0) {
            return res.status(404).json({ message: `Pessoa com ID ${id} não encontrada para exclusão.` });
        }
        return res.status(200).json({message: "Pessoa deletada permanentemente com sucesso."});
    }catch(erro){
        return res.status(500).json({message: `Erro interno ao tentar deletar: \n${erro.message}`})
    }
}
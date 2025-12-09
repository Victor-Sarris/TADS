import Loan from "./loan.model.js";
export const createLoan = async (loan)=>{
    return Loan.create(loan);
}
export const findAllLoans = async () =>{
    return Loan.findAll()
}
export const update = async (loan) =>{
    return Loan.update(loan, {where: {id: loan.id}})
}
export const deleteLoanById = async (loanId) =>{
    return Loan.destroy({where: { id: loanId }})
}
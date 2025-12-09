import express from "express";
import {newLoan, listLoans, deleteLoan, updateLoan } from "./loan.controller.js"
import {authenticate, authorizaAdmin} from "../../middleware/authenticate.js"

const loanRouter = express.Router();
loanRouter.get("/loans", authenticate, listLoans)
loanRouter.post("/loans", authenticate,  authorizaAdmin, newLoan)
loanRouter.post("/loans/update", authenticate, authorizaAdmin, updateLoan)
loanRouter.post("/loans/delete", authenticate, authorizaAdmin, deleteLoan)

export default loanRouter; 
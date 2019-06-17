#pragma once

#include <Windows.h>

#include "IMemorySource.hpp"
#include "SafeHandle.hpp"

class UsermodeMemory final : public IMemorySource
{
	//
	//
	// Variables
	//
	//

	/**
	 * \brief The process handle.
	 */
	SafeHandle process_handle = nullptr;

public:

	//
	//
	// Constructor
	//
	//

	/**
	 * \brief Opens the process.
	 * \param process_id the id of the process
	 */
	explicit UsermodeMemory(DWORD process_id);


	//
	//
	// Important functions
	//
	//

	/**
	 * \brief Reads the memory from the process.
	 * \param start_address the memory start address
	 * \param size the buffer size
	 * \return the memory buffer
	 */
	auto ReadMemory(DWORD_PTR start_address, SIZE_T size) -> std::shared_ptr<BYTE> override;


	//
	//
	// Checks
	//
	//

	/**
	 * \brief Checks whether the memory source is valid.
	 * \return true if valid
	 */
	auto IsValid() -> BOOL override;


	//
	//
	// Getters
	//
	//

	/**
	 * \brief Returns the base address.
	 * \return the base address of the process
	 */
	auto GetBaseAddress() -> DWORD_PTR override;
};
